#include <bits/stdc++.h>
using namespace std;

class CentroidDecomposition {
private:
    vector<vector<pair<int, int>>> &tree; // Граф дерева {сусід, вага}
    vector<bool> isCentroidProcessed;
    vector<int> subtreeSize;
    unordered_map<int, int> pathCounts;
    long long totalBalancedPaths = 0;

    void calculateSubtreeSizes(int node, int parent) {
        subtreeSize[node] = 1;
        for (auto &[neighbor, weight] : tree[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor]) {
                calculateSubtreeSizes(neighbor, node);
                subtreeSize[node] += subtreeSize[neighbor];
            }
        }
    }

    int findCentroid(int node, int parent, int totalSize) {
        for (auto &[neighbor, weight] : tree[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor] && subtreeSize[neighbor] > totalSize / 2) {
                return findCentroid(neighbor, node, totalSize);
            }
        }
        return node;
    }

    void collectPaths(int node, int parent, int currentSum, vector<int> &pathSums) {
        pathSums.push_back(currentSum);
        for (auto &[neighbor, weight] : tree[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor]) {
                collectPaths(neighbor, node, currentSum + weight, pathSums);
            }
        }
    }

    long long countBalancedPaths(const vector<int> &pathSums, int initialSum) {
        long long count = 0;
        for (int sum : pathSums) {
            int target = initialSum - sum;
            if (pathCounts.count(target)) {
                count += pathCounts[target];
            }
        }
        return count;
    }

    void addPathCounts(const vector<int> &pathSums) {
        for (int sum : pathSums) {
            pathCounts[sum]++;
        }
    }

    void removePathCounts(const vector<int> &pathSums) {
        for (int sum : pathSums) {
            pathCounts[sum]--;
        }
    }

    void processCentroid(int node) {
        isCentroidProcessed[node] = true;
        pathCounts.clear();
        pathCounts[0] = 1; // Порожній шлях має суму 0

        for (auto &[neighbor, weight] : tree[node]) {
            if (!isCentroidProcessed[neighbor]) {
                vector<int> pathSums;
                collectPaths(neighbor, node, weight, pathSums);

                totalBalancedPaths += countBalancedPaths(pathSums, 0);
                addPathCounts(pathSums);
            }
        }

        for (auto &[neighbor, weight] : tree[node]) {
            if (!isCentroidProcessed[neighbor]) {
                vector<int> pathSums;
                collectPaths(neighbor, node, weight, pathSums);
                removePathCounts(pathSums);
            }
        }
    }

    void decomposeTree(int node) {
        calculateSubtreeSizes(node, -1);
        int totalSize = subtreeSize[node];
        int centroid = findCentroid(node, -1, totalSize);

        processCentroid(centroid);

        for (auto &[neighbor, weight] : tree[centroid]) {
            if (!isCentroidProcessed[neighbor]) {
                decomposeTree(neighbor);
            }
        }
    }

public:
    CentroidDecomposition(vector<vector<pair<int, int>>> &graph) : tree(graph) {
        int n = tree.size();
        isCentroidProcessed.assign(n, false);
        subtreeSize.assign(n, 0);
    }

    long long solve() {
        decomposeTree(0);
        return totalBalancedPaths;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        int weight = (t == 0 ? 1 : -1);
        tree[a].emplace_back(b, weight);
        tree[b].emplace_back(a, weight);
    }

    CentroidDecomposition cd(tree);
    cout << cd.solve() << endl;

    return 0;
}
