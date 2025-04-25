#include <iostream>
#include <vector>

// Функція для знаходження останньої цифри k-го числа Фібоначчі
int lastDigitFibonacci(long long k) {
    if (k <= 1) {
        return static_cast<int>(k);
    }

    std::vector<int> fib(60, 0);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 60; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    }

    return fib[k % 60];
}

int main() {
    long long k;
    std::cout << "Введіть k: ";
    std::cin >> k;

    int result = lastDigitFibonacci(k);

    std::cout << "Остання цифра " << k << "-го числа Фібоначчі: " << result << std::endl;

    return 0;
}
