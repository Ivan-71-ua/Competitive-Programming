from itertools import combinations

# Функція для пошуку кореня в системі неперетинних множин
def find(parent, i):
    if parent[i] == i:
        return i
    return find(parent, parent[i])

# Об'єднання двох множин
def union(parent, rank, x, y):
    xroot = find(parent, x)
    yroot = find(parent, y)

    if rank[xroot] < rank[yroot]:
        parent[xroot] = yroot
    elif rank[xroot] > rank[yroot]:
        parent[yroot] = xroot
    else:
        parent[yroot] = xroot
        rank[xroot] += 1

# Алгоритм Крускала для пошуку MST
def kruskal(n, edges):
    parent = []
    rank = []

    # Ініціалізація батьків та рангу
    for node in range(n):
        parent.append(node)
        rank.append(0)

    mst_cost = 0
    mst_edges = []
    
    edges = sorted(edges, key=lambda item: item[2])  # Сортування за вагою ребра

    e = 0  # Початковий індекс для обраних ребер
    i = 0  # Ініціалізація індексу для сортування ребер
    while e < n - 1 and i < len(edges):
        u, v, w = edges[i]
        i += 1
        x = find(parent, u)
        y = find(parent, v)

        if x != y:
            e += 1
            mst_cost += w
            mst_edges.append((u, v, w))
            union(parent, rank, x, y)

    # Якщо MST не містить усіх вершин, то повертаємо порожній MST
    if e != n - 1:
        return None, None

    return mst_cost, mst_edges

# Перевірка 2-зв'язності: чи є у графа мости
def is_biconnected(n, edges):
    graph = [[] for _ in range(n)]
    for u, v, w in edges:
        graph[u].append(v)
        graph[v].append(u)

    def dfs(u, parent, visited, disc, low, bridges, time):
        visited[u] = True
        disc[u] = low[u] = time[0]
        time[0] += 1

        for v in graph[u]:
            if not visited[v]:
                dfs(v, u, visited, disc, low, bridges, time)
                low[u] = min(low[u], low[v])

                if low[v] > disc[u]:
                    bridges.append((u, v))
            elif v != parent:
                low[u] = min(low[u], disc[v])

    visited = [False] * n
    disc = [-1] * n
    low = [-1] * n
    bridges = []
    time = [0]

    dfs(0, -1, visited, disc, low, bridges, time)

    if len(bridges) > 0 or not all(visited):
        return False
    return True

# Основна функція
def solve():
    test_case = 1
    while True:
        n, m = map(int, input().split())
        if n == 0 and m == 0:
            break
        
        edges = []
        for _ in range(m):
            b1, b2, c = map(int, input().split())
            edges.append((b1 - 1, b2 - 1, c))
        
        mst_cost, mst_edges = kruskal(n, edges)

        if mst_cost is None:
            print(f"There is no reliable net possible for test case {test_case}.")
        else:
            min_cost = float('inf')
            # Перебір всіх підмножин, які включають MST та одне додаткове ребро
            for i in range(1, m + 1):
                for comb in combinations(edges, i):
                    if is_biconnected(n, comb):
                        cost = sum(w for _, _, w in comb)
                        min_cost = min(min_cost, cost)
            
            if min_cost < float('inf'):
                print(f"The minimal cost for test case {test_case} is {min_cost}.")
            else:
                print(f"There is no reliable net possible for test case {test_case}.")
        
        test_case += 1

solve()
