#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

void createGraph(const vector<pair<int, int>>& edges, unordered_map<int, char>& bijection, unordered_map<int, vector<int>>& graph) {
	for (const auto& edge : edges) {
		int u = edge.first;
		int v = edge.second;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	// Sort adjacency lists lexicographically based on bijection
	for (auto& [key, neighbors] : graph) {
		sort(neighbors.begin(), neighbors.end(), [&bijection](int a, int b) {
			return bijection[a] < bijection[b];
		});
	}
}

string dfs(unordered_map<int, vector<int>>& graph, int start, unordered_map<int, char>& bijection) {
	set<int> visited;
	vector<int> stack = {start};
	string result;

	while (!stack.empty()) {
		int vertex = stack.back();
		stack.pop_back();
		if (visited.find(vertex) == visited.end()) {
			visited.insert(vertex);
			result += bijection[vertex];
			for (auto it = graph[vertex].rbegin(); it != graph[vertex].rend(); ++it) {
				if (visited.find(*it) == visited.end()) {
					stack.push_back(*it);
				}
			}
		}
	}
	return result;
}

string bfs(unordered_map<int, vector<int>>& graph, int start, unordered_map<int, char>& bijection) {
	set<int> visited;
	queue<int> q;
	q.push(start);
	string result;

	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		if (visited.find(vertex) == visited.end()) {
			visited.insert(vertex);
			result += bijection[vertex];
			for (const int& neighbor : graph[vertex]) {
					if (visited.find(neighbor) == visited.end()) {
						q.push(neighbor);
					}
			}
		}
	}
	return result;
}

int main() {
	vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 10}, {4, 5}, {5, 6}, {6, 7}, {6, 8}, {6, 2}, {5, 8}, {8, 9}, {3, 11}};
unordered_map<int, char> bijection = {{1, 'j'}, {2, 'e'}, {3, 'f'}, {4, 'a'}, {5, 'b'}, {6, 'c'}, {7, 'd'}, {8, 'g'}, {9, 'i'}, {10, 'k'}, {11, 'h'}};
	char start_letter = 'a';

	// Find the start vertex corresponding to the start_letter
	int start_vertex = -1;
	for (const auto& [key, value] : bijection) {
		if (value == start_letter) {
			start_vertex = key;
			break;
		}
	}

	if (start_vertex == -1) {
		cout << "Start vertex not found!" << endl;
		return -1;
	}

	unordered_map<int, vector<int>> graph;
	createGraph(edges, bijection, graph);

	string dfs_result = dfs(graph, start_vertex, bijection);
	string bfs_result = bfs(graph, start_vertex, bijection);

	cout << "DFS Traversal: " << dfs_result << endl;
	cout << "BFS Traversal: " << bfs_result << endl;

	return 0;
}




