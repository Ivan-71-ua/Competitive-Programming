#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> operations;

    for (int i = 0; i < N; i++) {
        while (A[i] != i + 1) {
            int j = A[i] - 1;  
            swap(A[i], A[j]);
            operations.push_back({i + 1, j + 1}); 
        }
    }

    cout << operations.size() << endl;


    for (const auto& op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}
