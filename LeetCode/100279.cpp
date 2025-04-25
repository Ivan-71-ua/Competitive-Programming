#include <bits/stdc++.h>



class Solution {
public:
    std::vector<int> minimumTime(int n, std::vector<std::vector<int>>& edges, std::vector<int>& disappear) {
        // Build graph
        std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        std::vector<int> answer(n, -1); // Initialize answer array
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq; // Min-heap priority queue

        pq.push({0, 0}); // Start from node 0 with time 0

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (answer[node] != -1) continue; // Node already visited

            answer[node] = time;

            for (const auto& [nextNode, edgeTime] : graph[node]) {
                if (time + edgeTime >= disappear[nextNode]) continue; // Node disappears before reaching it
                pq.push({time + edgeTime, nextNode});
            }
        }

        return answer;
    }
};
