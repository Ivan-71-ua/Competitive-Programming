#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления площади треугольника по координатам вершин
double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0);
}

int main() {
    // Чтение числа столбов
    int n;
    cin >> n;

    // Чтение координат столбов
    int x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    double maxArea = 0;

    // Перебор всех комбинаций троек столбов
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                // Проверка условий параллельности осей
                if ((x[i] == x[j] && x[j] == x[k]) || (y[i] == y[j] && y[j] == y[k])) {
                    // Вычисление площади треугольника и обновление максимальной площади
                    double area = triangleArea(x[i], y[i], x[j], y[j], x[k], y[k]);
                    maxArea = max(maxArea, area);
                }
            }
        }
    }

    // Вывод результата (удвоенной максимальной площади)
    cout << static_cast<int>(maxArea * 2) << endl;

    return 0;
}
