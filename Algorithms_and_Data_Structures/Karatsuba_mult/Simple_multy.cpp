#include <bits/stdc++.h>



std::vector<int> multiply(const std::vector<int>& x, const std::vector<int>& y, int base = 10) {
    int l = x.size();
    int r = y.size();
    std::vector<int> res(l + r, 0);  // результат може мати максимум l + r цифр
    for (int i = 0; i < r; i++) {
        int carry = 0;
        for (int j = 0; j < l; j++) {
            res[i + j] += carry + x[j] * y[i];  // x[j] та y[i], оскільки в псевдокоді перший цикл по y
            carry = res[i + j] / base;
            res[i + j] %= base;
        }
        res[i + l] += carry;
    }
    // Видаляємо ведучі нулі
    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }
    return res;
}

int main() {
    std::vector<int> x = {2, 4, 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9,9,9,9,9,9};  // число 342
    std::vector<int> y = {1, 2, 1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};  // число 121
    std::vector<int> result = multiply(x, y);
    // Виводимо результат у правильному порядку
    for (int i = result.size() - 1; i >= 0; i--) {
        std::cout << result[i];
    }
    std::cout << std::endl;  // Виведе 41382
    return 0;
}
