#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;

//Підготовка до функції коду Прюфера
const int MAXN = 1000;
int n;
vector<int> g[MAXN];
int degree[MAXN];
bool killed[MAXN];

// Функція для створення графа з ребер та бієкції
std::vector<std::vector<int>> createGraph(const vector<pair<char, char>>& edges, const unordered_map<char, int>& bijection, unordered_map<int, vector<int>>& graph) {
    int max = -1;
    for (auto now : bijection)
    {
        max = std::max(max, now.second);
    }
    std::vector<std::vector<int>> graf_list(max + 1);
    for (const auto& edge : edges) {
        int u = bijection.at(edge.first);
        int v = bijection.at(edge.second);
        graph[u].push_back(v);
        graph[v].push_back(u);
        graf_list[u].push_back(v);
        graf_list[v].push_back(u);
    }
    // Сортуємо списки суміжності лексикографічно
    for (auto& [key, neighbors] : graph) {
        sort(neighbors.begin(), neighbors.end());
    }
    return graf_list;
}

// Функція для знаходження коду Прюфера
vector<int> prufer_code(int n) {
    set<int> leaves;
    for (int i = 1; i <= n; i++) {
        degree[i] = (int)g[i].size();
        if (degree[i] == 1)
            leaves.insert(i);
        killed[i] = false;
    }
    vector<int> result(n - 2);
    for (int iter = 0; iter < n - 2; iter++) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        killed[leaf] = true;
        int v;
        for (size_t i = 0; i < g[leaf].size(); i++)
            if (!killed[g[leaf][i]])
                v = g[leaf][i];
        result[iter] = v;
        if (--degree[v] == 1)
            leaves.insert(v);
    }
    return result;
}
//Функція для знаходження відстаней від певної вершини до всіх інших
std::vector<int> BFS(const std::vector<std::vector<int>>& graph, int src, std::vector<int>& dist) {
	int n = graph.size();
	std::vector<int> used(n, 0);
	std::queue<int> q;
	q.push(src);
	used[src] = 1;
	dist[src] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int to : graph[v]) {
            if (!used[to]) {
                used[to] = 1;
                dist[to] = dist[v] + 1;
                q.push(to);
            }
		}
	}
	return used;
}

//Функція знаходження центру дерева
std::vector<int> findTreeCenters(const std::vector<std::vector<int>>& graph) {
	int n = graph.size();
	std::vector<int> dist1(n), dist2(n);
	
	BFS(graph, 1, dist1);
	int farthest = 1;
	for (int i = 1; i < n; i++) {
		if (dist1[i] > dist1[farthest]) {
			farthest = i;
		}
	}
	
	BFS(graph, farthest, dist1);
	int otherFarthest = farthest;
	for (int i = 1; i < n; i++) {
		if (dist1[i] > dist1[otherFarthest]) {
			otherFarthest = i;
		}
	}
	
	BFS(graph, otherFarthest, dist2);
	int diameter = dist1[otherFarthest];
	std::vector<int> centers;
	int radius = (diameter + 1) / 2;
	for (int i = 1; i < n; i++) {
		if (dist1[i] == radius && dist2[i] == diameter - radius) {
			centers.push_back(i);
		} else if (dist2[i] == radius && dist1[i] == diameter - radius) {
			centers.push_back(i);
		}
	}
	return centers;
}

//Функція знаходження переферії дерева
vector<int> findPeriphery(std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> max_dist_for_every_vertex(n);
    for (int i = 1; i < n; i++)
    {
        std::vector<int> dist(n);
        BFS(graph, i, dist);
        int max = *std::max_element(dist.begin(), dist.end());
        max_dist_for_every_vertex[i] = max;
    }
    int max_dist = *std::max_element(max_dist_for_every_vertex.begin(), max_dist_for_every_vertex.end());
    std::vector<int> res;
    for (int i = 1; i < n; i++)
    {
        if(max_dist_for_every_vertex[i] == max_dist) {
            res.push_back(i);
        }
    }
    return res;
}

//Функція знаходження кількості вершин на ярусах дерева
std::vector<int> countVerticesPerLevel(std::vector<std::vector<int>>& graph, int root) {
    std::vector<bool> used(graph.size());
    std::vector<int> res;
    std::queue<int> way;
    way.push(root);
    used[root] = true;
    while(true) {
        std::queue<int> count_vertex;
        while(!way.empty()) {
            int vertex = way.front();
            way.pop();
            for (int i = 0; i < graph[vertex].size(); i++)
            {
                if(!used[graph[vertex][i]]) {
                    count_vertex.push(graph[vertex][i]);
                    used[graph[vertex][i]] = true;
                }
            }
        }
        way = count_vertex;
        if(way.size() == 0) break;
        res.push_back(way.size());
    }
    return res;
}



int main() {
    // Вхідні дані для графа та бієкції
    vector<pair<char, char>> edges = {{'i', 'a'}, {'a', 'g'}, {'g', 'e'}, {'g', 'b'}, {'g', 'c'}, {'c', 'd'}, {'c', 'f'}, {'c', 'l'}, {'b', 'k'}, {'b', 'h'}, {'b', 'j'}};
    unordered_map<char, int> bijection = {{'a', 7}, {'b', 10}, {'c', 12}, {'d', 2}, {'e', 5}, {'f', 11}, {'g', 1}, {'h', 3}, {'i', 9}, {'j', 8}, {'k', 4}, {'l', 6}};

    // Побудова графа
    unordered_map<int, vector<int>> graph;
    std::vector<std::vector<int>> graf_list = createGraph(edges, bijection, graph);

    // Знаходження коду Прюфера
    n = bijection.size();
    for (const auto& [key, value] : graph) {
        g[key] = value;
    }
    vector<int> prufer = prufer_code(n);
    cout << "Prufer Code: ";
    for (int x : prufer) {
        cout << x << " ";
    }

    cout << endl;
    // Додавання нових ребер
    vector<pair<int, int>> newEdges = {{4, 13}, {7, 14}, {3, 15}};
    for (int i = 0; i < newEdges.size(); i++) {
        graf_list.push_back({});
    }
    for (const auto &edge : newEdges)
    {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
        graf_list[edge.first].push_back(edge.second);
        graf_list[edge.second].push_back(edge.first);
    }

    // Знаходження центру графа
    vector<int> centers = findTreeCenters(graf_list);
    cout << "Tree Centers: ";
    for (int center : centers) {
        cout << center << " "; // Виправлення індексації для виведення
    }
    cout << endl;

    // Знаходження периферії графа
    vector<int> periphery = findPeriphery(graf_list);
    cout << "Periphery: ";
    for (int vertex : periphery) {
        cout << vertex << " ";
    }
    cout << endl;

    //Зчитування кореня
    const int ROOT = 1;
    // Підрахунок кількості вершин на кожному ярусі
    vector<int> verticesPerLevel = countVerticesPerLevel(graf_list, ROOT); // Виправлення індексації для функції
    cout << "Vertices per Level (excluding root): ";
    for (int count : verticesPerLevel) {
        cout << count << " ";
    }
    cout << endl;
    return 0;
}


/*
vector<pair<char, char>> edges = {{'a', 'b'}, {'c', 'b'}, {'d', 'b'}, {'b', 'f'}, {'k', 'f'}, {'f', 'l'}, {'g', 'l'}, {'e', 'l'}, {'e', 'q'}, {'l', 'h'}, {'h', 'i'}};
    unordered_map<char, int> bijection = {{'a', 8}, {'b', 7}, {'c', 3}, {'d', 11}, {'f', 1}, {'k', 6}, {'l', 2}, {'h', 9}, {'e', 5}, {'q', 12}, {'g', 10}, {'i', 4}};
*/