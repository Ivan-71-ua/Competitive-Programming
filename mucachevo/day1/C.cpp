#include <bits/stdc++.h>

const int MAX_N = 100005;

class CentroidDecomposition {
public:
    std::vector<std::vector<int>> &graph;
    std::vector<bool> isCentroidProcessed;
    std::vector<int> subtreeSize;
    std::vector<char> ratings;
    bool isImpossible = false;

    CentroidDecomposition(std::vector<std::vector<int>> &tree) : graph(tree) {
        int n = graph.size();
        isCentroidProcessed.assign(n, false);
        subtreeSize.assign(n, 0);
        ratings.assign(n, 0);
        decomposeTree(0, 'A');
    }

private:
    void calculateSubtreeSizes(int node, int parent) {
        subtreeSize[node] = 1;
        for (int neighbor : graph[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor]) {
                calculateSubtreeSizes(neighbor, node);
                subtreeSize[node] += subtreeSize[neighbor];
            }
        }
    }

    int findCentroid(int node, int parent, int totalSize) {
        for (int neighbor : graph[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor] && subtreeSize[neighbor] > totalSize / 2) {
                return findCentroid(neighbor, node, totalSize);
            }
        }
        return node;
    }

    void decomposeTree(int node, char currentRating) {
        if (currentRating > 'Z') {
            isImpossible = true;
            return;
        }

        calculateSubtreeSizes(node, -1);
        int totalSize = subtreeSize[node];
        int centroid = findCentroid(node, -1, totalSize);

        ratings[centroid] = currentRating;
        isCentroidProcessed[centroid] = true;

        for (int neighbor : graph[centroid]) {
            if (!isCentroidProcessed[neighbor]) {
                decomposeTree(neighbor, currentRating + 1);
                if (isImpossible) return; 
            }
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    CentroidDecomposition cd(tree);

    if (cd.isImpossible) {
        std::cout << "Impossible!" << std::endl;
    } else {
        for (int i = 0; i < n; i++) {
            std::cout << cd.ratings[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
