#include <bits/stdc++.h>



// Функція класичного множення матриць
std::vector<std::vector<int>> multiply(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
	int n = a.size();
	std::vector<std::vector<int>> c(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

// Функції додавання та віднімання матриць
std::vector<std::vector<int>> add(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
	int n = a.size();
	std::vector<std::vector<int>> c(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return c;
}

std::vector<std::vector<int>> subtract(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
	int n = a.size();
	std::vector<std::vector<int>> c(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
	return c;
}

// Функція розбиття матриці на 4 підматриці
void splitMatrix(const std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& a11, std::vector<std::vector<int>>& a12, std::vector<std::vector<int>>& a21, std::vector<std::vector<int>>& a22) {
	int n = a.size() / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a11[i][j] = a[i][j];
			a12[i][j] = a[i][j + n];
			a21[i][j] = a[i + n][j];
			a22[i][j] = a[i + n][j + n];
		}
	}
}

// Функція збирання матриці з 4 підматриць
std::vector<std::vector<int>> collectMatrix(const std::vector<std::vector<int>>& a11, const std::vector<std::vector<int>>& a12, const std::vector<std::vector<int>>& a21, const std::vector<std::vector<int>>& a22) {
	int n = a11.size();
	std::vector<std::vector<int>> a(n * 2, std::vector<int>(n * 2, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = a11[i][j];
			a[i][j + n] = a12[i][j];
			a[i + n][j] = a21[i][j];
			a[i + n][j + n] = a22[i][j];
		}
	}
	return a;
}

// Рекурсивна функція для алгоритму Штрассена
std::vector<std::vector<int>> strassen(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
	int n = a.size();
	if (n <= 128) { // базовий випадок
		return multiply(a, b);
	}

	n /= 2;
	std::vector<std::vector<int>> a11(n, std::vector<int>(n)), a12(n, std::vector<int>(n)), a21(n, std::vector<int>(n)), a22(n, std::vector<int>(n));
	std::vector<std::vector<int>> b11(n, std::vector<int>(n)), b12(n, std::vector<int>(n)), b21(n, std::vector<int>(n)), b22(n, std::vector<int>(n));

	splitMatrix(a, a11, a12, a21, a22);
	splitMatrix(b, b11, b12, b21, b22);

	auto p1 = strassen(add(a11, a22), add(b11, b22));
	auto p2 = strassen(add(a21, a22), b11);
	auto p3 = strassen(a11, subtract(b12, b22));
	auto p4 = strassen(a22, subtract(b21, b11));
	auto p5 = strassen(add(a11, a12), b22);
	auto p6 = strassen(subtract(a21, a11), add(b11, b12));
	auto p7 = strassen(subtract(a12, a22), add(b21, b22));

	auto c11 = add(subtract(add(p1, p4), p5), p7);
	auto c12 = add(p3, p5);
	auto c21 = add(p2, p4);
	auto c22 = add(subtract(add(p1, p3), p2), p6);

	return collectMatrix(c11, c12, c21, c22);
}

// Функція для збільшення розміру матриць до найближчої степені 2
std::vector<std::vector<int>> resizeMatrix(const std::vector<std::vector<int>>& a, int newSize) {
	int n = a.size();
	std::vector<std::vector<int>> newMatrix(newSize, std::vector<int>(newSize, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			newMatrix[i][j] = a[i][j];
		}
	}
	return newMatrix;
}

// Функція для отримання найближчої степені 2
int nextPowerOf2(int n) {
	return std::pow(2, std::ceil(std::log2(n)));
}

// Основна функція для виклику алгоритму Штрассена
std::vector<std::vector<int>> strassenMultiply(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b) {
	int n = a.size();
	int m = a[0].size();
	int p = b[0].size();

	int newSize = nextPowerOf2(std::max({n, m, p}));
	auto newA = resizeMatrix(a, newSize);
	auto newB = resizeMatrix(b, newSize);

	auto result = strassen(newA, newB);

	std::vector<std::vector<int>> finalResult(n, std::vector<int>(p, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			finalResult[i][j] = result[i][j];
		}
	}
	return finalResult;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
	for (const auto& row : matrix) {
		for (int val : row) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	std::vector<std::vector<int>> a = {
		 {1, 2, 3, 4, 5, 6, 7},
		 {8,91,10,11, 12, 13,14	},
		 {15, 16, 17, 18, 19, 202, 1},
		 {12, 21, 23, 24, 45, 67, 53},
		 {3, 2, 64, 34, 3, 6, 3},
		 {57, 7, 74, 33, 2, 7, 11},
		 {55, 90, 345, 3, 2, 6, 77}

	};
	std::vector<std::vector<int>> b = {
		 {12, 1},
		 {4, 6},
		 {6, 2},
		 {3, 33},
		 {645, 6},
		 {64, 78},
		 {3, 9}};
	auto result = strassenMultiply(a, b);
	printMatrix(result);
	return 0;
}
