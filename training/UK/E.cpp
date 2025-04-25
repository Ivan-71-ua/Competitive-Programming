#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_efficiency(int N, int M, const vector<int>& A) {
    int max_eff = 0;
    vector<bool> used(N, false);  // Масив для відмітки використаних чіпів

    // Перебираємо всі можливі пари
    for (int i = 0; i + M < N; ++i) {
        // Якщо обидва чіпи ще не використані, розглядаємо їх як нейрон
        if (!used[i] && !used[i + M]) {
            int efficiency = A[i] + A[i + M];
            max_eff += efficiency;
            used[i] = used[i + M] = true;  // Відмічаємо чіпи як використані
        }
    }

    return max_eff;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << max_efficiency(N, M, A) << endl;

    return 0;
}
