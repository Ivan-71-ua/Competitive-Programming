from collections import defaultdict, deque
import heapq

def first(edges):
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    d = deque()
    degree = [0]*len(graph.keys())
    visit = set()
    for cur in graph.keys():
        degree[cur - 1] = len(graph[cur])
        if degree[cur - 1] == 1:
            d.append(cur)
    r = 0
    last = 0
    while d:
        last = len(d)
        for _ in range(last):
            cur = d.popleft()
            visit.add(cur)
            for nei in graph[cur]:
                degree[nei - 1] -= 1
                if degree[nei - 1] == 1 and nei not in visit:
                    d.append(nei)
        r += 1
    r -= 1
    return (r, r * 2) if last == 1 else (r + 1, ((r + 1) * 2) - 1)

def second(edges, start):
    graph = defaultdict(list)
    for u, v in edges:
        heapq.heappush(graph[u], v)
        heapq.heappush(graph[v], u)
    visit = set()
    res = []

    def dfs(cur):
        nonlocal res

        res.append(cur)
        visit.add(cur)
        while graph[cur]:
            nei = heapq.heappop(graph[cur])
            if nei not in visit:
                dfs(nei)
        return res
    return dfs(start)

def third(edges, start):
    graph = defaultdict(list)
    for u, v in edges:
        heapq.heappush(graph[u], v)
        heapq.heappush(graph[v], u)

    new_graph = defaultdict(list)
    visit = set()

    def dfs(cur, per):
        nonlocal new_graph
        if not cur:
            return
        visit.add(cur)

        next = nei = None
        while graph[cur]:
            next = heapq.heappop(graph[cur])
            if next not in visit:
                break
            else: next = None

        if next:new_graph[cur].append(next)

        if per:
            while graph[per]:
                nei = heapq.heappop(graph[per])
                if nei not in visit:
                    break
                else: nei = None

            if nei:new_graph[cur].append(nei)

        dfs(next, cur)
        dfs(nei, per)

    dfs(start, None)
    d = deque([start])
    visit.clear()
    res = []
    while d:
        cur = d.popleft()
        visit.add(cur)
        res.append(cur)
        for nei in new_graph[cur]:
            if nei not in visit:
                d.append(nei)
    return res


def printTreeEdges(prufer, m):
    global edges
    vertices = m + 2

    vertex_set = [0] * vertices

    for i in range(vertices - 2):
        vertex_set[prufer[i] - 1] += 1

    print("The edge set E(G) is :")
    j = 0
    for i in range(vertices - 2):
        for j in range(vertices):
            if (vertex_set[j] == 0):
                vertex_set[j] = -1
                edges.append((j+1, prufer[i]))
                print( (j + 1), "-", prufer[i], "\n", sep="", end="")
                vertex_set[prufer[i] - 1] -= 1
                break

    j = 0
    p = []
    for i in range(vertices):
        if (vertex_set[i] == 0 and j == 0):
            print( (i + 1), "-", sep="", end="")
            p.append((i+1))
            j += 1
        elif (vertex_set[i] == 0 and j == 1):
            print((i + 1))
            p.append((i + 1))
    edges.append(tuple(p))



prufer = [3, 2, 7, 11, 1, 2, 3, 6, 8, 12] # ввести код прюфера за зракзком
n = len(prufer)
edges = []
printTreeEdges(prufer, n)
radius, diameter = first(edges)
print()
print(f'радіус: {radius}, діаметер:{diameter}')
print('друге: ',*second(edges, 9)) # вказати вершину дерева
print('третє: ',*third(edges, 9))	