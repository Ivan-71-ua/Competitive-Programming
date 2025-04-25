#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

class CentroidDecomposition {
private:
    vector<vector<int>> tree; // Граф дерева
    vector<int> subtreeSize;  // Розміри піддерев
    vector<int> centroidParent; // Батьки центроїдів
    vector<bool> isCentroidProcessed; // Відмітка про обробку центроїда
    vector<int> maxDistance; // Максимальні відстані до найвіддаленішого вузла
    int currentSize; // Поточний розмір дерева

    void calculateSubtreeSizes(int node, int parent) {
        subtreeSize[node] = 1;
        for (int neighbor : tree[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor]) {
                calculateSubtreeSizes(neighbor, node);
                subtreeSize[node] += subtreeSize[neighbor];
            }
        }
    }

    int findCentroid(int node, int parent) {
        for (int neighbor : tree[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor] && subtreeSize[neighbor] > currentSize / 2) {
                return findCentroid(neighbor, node);
            }
        }
        return node;
    }

    void calculateMaxDistances(int node, int parent, int depth) {
        maxDistance[node] = max(maxDistance[node], depth);
        for (int neighbor : tree[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor]) {
                calculateMaxDistances(neighbor, node, depth + 1);
            }
        }
    }

    void processCentroid(int node) {
        isCentroidProcessed[node] = true;
        maxDistance[node] = 0;

        for (int neighbor : tree[node]) {
            if (!isCentroidProcessed[neighbor]) {
                calculateMaxDistances(neighbor, node, 1);
            }
        }
    }

public:
    CentroidDecomposition(int n) {
        tree.resize(n);
        subtreeSize.resize(n, 0);
        centroidParent.resize(n, -1);
        isCentroidProcessed.resize(n, false);
        maxDistance.resize(n, 0);
    }

    void addEdge(int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    void decomposeTree(int node, int parent) {
        calculateSubtreeSizes(node, -1);
        currentSize = subtreeSize[node];
        int centroid = findCentroid(node, -1);

        centroidParent[centroid] = parent;
        processCentroid(centroid);

        for (int neighbor : tree[centroid]) {
            if (!isCentroidProcessed[neighbor]) {
                decomposeTree(neighbor, centroid);
            }
        }
    }

    void buildNode(int parent) {
        if (parent != -1) {
            addEdge(parent, tree.size());
        }
        tree.emplace_back();
        maxDistance.push_back(0);
        subtreeSize.push_back(0);
        isCentroidProcessed.push_back(false);
        centroidParent.push_back(-1);
    }

    int queryMaxDistance(int node) {
        return maxDistance[node];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    CentroidDecomposition cd(1); // Починаємо з однієї вершини
    cd.buildNode(-1); // Створюємо перший вузол (корінь)

    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;

        if (query[0] == 'B') {
            int parent;
            cin >> parent;
            if (parent != -1) {
                cd.buildNode(parent - 1); // Побудувати новий клас, зв'язати з parent
            } else {
                cd.buildNode(-1); // Створити новий вузол без з'єднання
            }
        } else if (query[0] == 'Q') {
            int node;
            cin >> node;
            cout << cd.queryMaxDistance(node - 1) << '\n'; // Вивести відстань
        }
    }

    return 0;
}
