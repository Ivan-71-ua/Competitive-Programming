


#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<bool> is_prime = sieve(n);
    vector<int> primes;
    vector<int> non_primes;
    for (int i = 1; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        } else {
            non_primes.push_back(i);
        }
    }

    vector<int> count_unique(n + 1, 0);
    int len_primes = primes.size();

    for (int i = 0; i <= len_primes - m; ++i) {
        bool valid = true;
        for (int j = 0; j < m; ++j) {
            if ((s[j] == 'Y' && !is_prime[primes[i + j]]) ||
                (s[j] == 'N' && is_prime[primes[i + j]])) {
                valid = false;
                break;
            }
        }
        if (valid) {
            for (int j = 0; j < m; ++j) {
                count_unique[primes[i + j]]++;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        if (count_unique[i] == 1) {
            result++;
        }
    }

    cout << result << endl;
    return 0;
}
