#include <bits/stdc++.h>
using namespace std;

class CentroidDecomposition {
private:
    const int ALPHABET_SIZE = 20; // Літери від 'a' до 't'
    vector<vector<int>> &tree;
    string labels;
    vector<int> subtreeSize;
    vector<int> centroidParent;
    vector<bool> isCentroidProcessed;
    vector<long long> result;
    unordered_map<int, long long> maskFrequency;

    void calculateSubtreeSizes(int node, int parent) {
        subtreeSize[node] = 1;
        for (int neighbor : tree[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor]) {
                calculateSubtreeSizes(neighbor, node);
                subtreeSize[node] += subtreeSize[neighbor];
            }
        }
    }

    int findCentroid(int node, int parent, int totalSize) {
        for (int neighbor : tree[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor] && subtreeSize[neighbor] > totalSize / 2) {
                return findCentroid(neighbor, node, totalSize);
            }
        }
        return node;
    }

    void collectMasks(int node, int parent, int currentMask, vector<pair<int, int>> &masks) {
        masks.emplace_back(currentMask, node);
        for (int neighbor : tree[node]) {
            if (neighbor != parent && !isCentroidProcessed[neighbor]) {
                int newMask = currentMask ^ (1 << (labels[neighbor] - 'a'));
                collectMasks(neighbor, node, newMask, masks);
            }
        }
    }

    long long countPalindromicPaths(vector<pair<int, int>> &masks, int rootMask) {
        long long count = 0;
        for (auto &[mask, node] : masks) {
            int fullMask = mask ^ rootMask;
            if (__builtin_popcount(fullMask) <= 1) {
                count++;
            }
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                if (__builtin_popcount(fullMask ^ (1 << i)) <= 1) {
                    count += maskFrequency[mask ^ (1 << i)];
                }
            }
        }
        return count;
    }

    void updateMaskFrequencies(vector<pair<int, int>> &masks) {
        for (auto &[mask, node] : masks) {
            maskFrequency[mask]++;
        }
    }

    void clearMaskFrequencies(vector<pair<int, int>> &masks) {
        for (auto &[mask, node] : masks) {
            maskFrequency[mask]--;
        }
    }

    void processCentroid(int node) {
        isCentroidProcessed[node] = true;
        int rootMask = 1 << (labels[node] - 'a');
        maskFrequency.clear();

        for (int neighbor : tree[node]) {
            if (!isCentroidProcessed[neighbor]) {
                vector<pair<int, int>> masks;
                collectMasks(neighbor, node, rootMask, masks);
                result[node] += countPalindromicPaths(masks, rootMask);
                updateMaskFrequencies(masks);
            }
        }

        for (int neighbor : tree[node]) {
            if (!isCentroidProcessed[neighbor]) {
                vector<pair<int, int>> masks;
                collectMasks(neighbor, node, rootMask, masks);
                clearMaskFrequencies(masks);
            }
        }

        result[node]++; // Усі шляхи, що починаються і закінчуються в поточному вузлі.
    }

    void decomposeTree(int node, int parent) {
        calculateSubtreeSizes(node, -1);
        int totalSize = subtreeSize[node];
        int centroid = findCentroid(node, -1, totalSize);

        processCentroid(centroid);

        for (int neighbor : tree[centroid]) {
            if (!isCentroidProcessed[neighbor]) {
                decomposeTree(neighbor, centroid);
            }
        }
    }

public:
    CentroidDecomposition(vector<vector<int>> &graph, string &labels)
        : tree(graph), labels(labels) {
        int n = tree.size();
        subtreeSize.resize(n);
        centroidParent.assign(n, -1);
        isCentroidProcessed.assign(n, false);
        result.assign(n, 0);
        decomposeTree(0, -1);
    }

    vector<long long> getResult() {
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    string labels;
    cin >> labels;

    CentroidDecomposition cd(tree, labels);
    vector<long long> result = cd.getResult();

    for (long long value : result) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
