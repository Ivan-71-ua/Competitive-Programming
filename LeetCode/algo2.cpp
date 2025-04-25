#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n, k, m;
    std::cin >> n >> k >> m;

    // DP arrays for clockwise and counterclockwise walks
    std::vector<std::vector<int>> dp_clockwise(n + 1, std::vector<int>(m + 1, 0));
    std::vector<std::vector<int>> dp_counterclockwise(n + 1, std::vector<int>(m + 1, 0));

    // Initialize the DP array for the starting point
    for (int i = 1; i <= n; ++i) {
        dp_clockwise[i][0] = 1;
        dp_counterclockwise[i][0] = 1;
    }

    // Fill the DP tables
    for (int step = 1; step <= m; ++step) {
        for (int i = 1; i <= n; ++i) {
            dp_clockwise[i][step] = (dp_clockwise[(i - 1 + n - 1) % n + 1][step - 1] + dp_clockwise[(i + 1 - 1) % n + 1][step - 1]) % MOD;
            dp_counterclockwise[i][step] = (dp_counterclockwise[(i + 1 - 1) % n + 1][step - 1] + dp_counterclockwise[(i - 1 + n - 1) % n + 1][step - 1]) % MOD;
        }
    }

    // Count all valid walks
    int total_walks = 0;
    for (int start = 1; start <= n; ++start) {
        for (int length = 1; length <= k; ++length) {
            int end = (start + length - 1 - 1) % n + 1;
            for (int steps = 1; steps <= m; ++steps) {
                total_walks = (total_walks + dp_clockwise[end][steps]) % MOD;
                total_walks = (total_walks + dp_counterclockwise[end][steps]) % MOD;
            }
        }
    }

    std::cout << total_walks << std::endl;
    return 0;
}
