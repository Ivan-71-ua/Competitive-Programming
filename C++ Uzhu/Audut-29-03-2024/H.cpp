#include <bits/stdc++.h>

int main() {
	std::string boards;
	const double INF = std::numeric_limits<double>::infinity();
	while (std::cin >> boards) {
		boards = " " + boards; // Добавляем пробел для сдвига позиций
		std::vector<double> c(boards.length()); // Инициализируем вектор для хранения стоимости починки
		c[0] = 0; // Начальное значение
		for (size_t i = 1; i < boards.length(); i++) {
				c[i] = INF; // Инициализация INF для каждой позиции
				
				if (boards[i] == '.') // Если доска целая
					c[i] = c[i - 1]; // То стоимость такая же как и для предыдущей позиции
				else {
					for (size_t j = 0; j < i; j++) {
						c[i] = std::min(c[i], c[j] + std::sqrt(1.0 * (i - j))); // Проверяем минимальную стоимость починки
					}
				}
		}
		std::cout << std::fixed << std::setprecision(4);  
		std::cout << c[boards.length() - 1] << std::endl; // Выводим результат
	}
}
