#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Функція для знаходження всіх простих чисел до n за допомогою решета Ератосфена
vector<bool> sieve_of_eratosthenes(int n) {
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
    int N, M;
    cin >> N >> M;
    string subset_description;
    cin >> subset_description;

    // Отримуємо решето Ератосфена для перевірки простоти чисел до N
    vector<bool> is_prime = sieve_of_eratosthenes(N);

    // Вектори для зберігання найлівіших та найправіших позицій для чисел з послідовності
    vector<int> left_positions(M, -1); // зберігає найлівішу позицію для кожного з M елементів
    vector<int> right_positions(M, -1); // зберігає найправішу позицію для кожного з M елементів

    // Жадний прохід зліва направо
    int prime_index = 0;
    int non_prime_index = 0;

    for (int i = 1; i <= N; ++i) {
        if (prime_index < M && subset_description[prime_index] == 'Y' && is_prime[i]) {
            left_positions[prime_index] = i;
            ++prime_index;
        }
        if (non_prime_index < M && subset_description[non_prime_index] == 'N' && !is_prime[i]) {
            left_positions[non_prime_index] = i;
            ++non_prime_index;
        }
    }

    // Жадний прохід справа наліво
    prime_index = M - 1;
    non_prime_index = M - 1;

    for (int i = N; i >= 1; --i) {
        if (prime_index >= 0 && subset_description[prime_index] == 'Y' && is_prime[i]) {
            right_positions[prime_index] = i;
            --prime_index;
        }
        if (non_prime_index >= 0 && subset_description[non_prime_index] == 'N' && !is_prime[i]) {
            right_positions[non_prime_index] = i;
            --non_prime_index;
        }
    }

    // Підрахунок кількості чисел, які можна визначити унікально
    int unique_count = 0;
    for (int i = 0; i < M; ++i) {
        if (left_positions[i] == right_positions[i] && left_positions[i] != -1) {
            ++unique_count;
        }
    }

    // Виводимо кількість чисел, які можна визначити унікально
    cout << unique_count << endl;

    return 0;
}
