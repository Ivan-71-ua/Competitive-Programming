
#pragma GCC optimize("Ofast", "unroll-loops")
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

const int MAXN = 200007;  // Максимальна кількість точок
int segmentTree[MAXN << 2];  // Дерево відрізків для зберігання максимальних y
std::set<int> pointsSet[MAXN];  // Множина для зберігання y для кожної x
int compressedX[MAXN];  // Компресовані значення x

struct Request {
	int type;  // 1 = add, 2 = remove, 3 = find
	int x, y;  // координати x і y
};

std::vector<Request> requests;

// Функція побудови дерева відрізків
void buildTree(int node, int left, int right) {
	segmentTree[node] = -1;  // Ініціалізація мінімальним значенням
	if (left == right) return;
	int mid = (left + right) / 2;
	buildTree(node * 2, left, mid);
	buildTree(node * 2 + 1, mid + 1, right);
}

// Функція оновлення дерева відрізків
void updateTree(int node, int left, int right, int pos) {
	if (left == right) {
		if (!pointsSet[pos].empty()) {
			segmentTree[node] = *pointsSet[pos].rbegin();  // Найбільший y
		} else {
			segmentTree[node] = -1;
		}
		return;
	}

	int mid = (left + right) / 2;
	if (pos <= mid) updateTree(node * 2, left, mid, pos);
	else updateTree(node * 2 + 1, mid + 1, right, pos);

	segmentTree[node] = std::max(segmentTree[node * 2], segmentTree[node * 2 + 1]);
}

// Функція для запиту дерева відрізків
int queryTree(int node, int left, int right, int xLimit, int yLimit) {
	if (right <= xLimit || segmentTree[node] <= yLimit) return -1;  // Якщо не відповідає критеріям
	if (left == right) return left;

	int mid = (left + right) / 2;
	int result = queryTree(node * 2, left, mid, xLimit, yLimit);
	if (result == -1) result = queryTree(node * 2 + 1, mid + 1, right, xLimit, yLimit);
	return result;
}

int main() {
	int n;
	std::cin >> n;
	requests.resize(n);

	// Зчитуємо запити та зберігаємо всі x для компресії
	for (int i = 0; i < n; i++) {
		std::string operation;
		std::cin >> operation >> requests[i].x >> requests[i].y;

		if (operation == "add") requests[i].type = 1;
		else if (operation == "remove") requests[i].type = 2;
		else if (operation == "find") requests[i].type = 3;

		compressedX[i] = requests[i].x;
	}

	// Компресія координат x
	std::sort(compressedX, compressedX + n);
	int compressedCount = std::unique(compressedX, compressedX + n) - compressedX;

	// Побудова дерева відрізків
	buildTree(1, 1, compressedCount);

	// Обробка кожного запиту
	for (int i = 0; i < n; i++) {
		int compressedPos = std::lower_bound(compressedX, compressedX + compressedCount, requests[i].x) - compressedX + 1;
		int y = requests[i].y;

		if (requests[i].type == 1) {  // Запит "add"
			pointsSet[compressedPos].insert(y);
			updateTree(1, 1, compressedCount, compressedPos);
		} else if (requests[i].type == 2) {  // Запит "remove"
			pointsSet[compressedPos].erase(y);
			updateTree(1, 1, compressedCount, compressedPos);
		} else if (requests[i].type == 3) {  // Запит "find"
			int result = queryTree(1, 1, compressedCount, compressedPos, y);
			if (result == -1) {
				std::cout << "-1\n";
			} else {
				std::cout << compressedX[result - 1] << " " << *pointsSet[result].upper_bound(y) << "\n";
			}
		}
	}

	return 0;
}
