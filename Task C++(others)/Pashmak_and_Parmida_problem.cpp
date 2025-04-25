#include <iostream>
#include <vector>
#include <map>

class SegmentTree {
public:
	std::vector<int> tree;
	int n;

	SegmentTree(int size) : n(size) {
		tree.assign(4 * n, 0);  // Ініціалізація дерева
	}

	// Оновлення значення в дереві відрізків
	void update(int v, int tl, int tr, int pos, int new_val) {
		if (tl == tr) {
			tree[v] += new_val;  // Якщо ми дійшли до листка, оновлюємо значення
		} else {
			int tm = (tl + tr) / 2;
			if (pos <= tm) {
				update(v * 2, tl, tm, pos, new_val);  // Оновлюємо ліву половину
			} else {
				update(v * 2 + 1, tm + 1, tr, pos, new_val);  // Оновлюємо праву половину
			}
			tree[v] = tree[v * 2] + tree[v * 2 + 1];  // Оновлюємо поточний вузол
		}
	}

	// Запит на суму в діапазоні [l, r]
	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) return 0;  // Якщо діапазон некоректний
		if (l == tl && r == tr) {
			return tree[v];  // Якщо діапазон повністю відповідає поточному вузлу
		}
		int tm = (tl + tr) / 2;
		return query(v * 2, tl, tm, l, std::min(r, tm)) +
			query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
	}
};

int main() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);  // Масив елементів
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];  // Читання вхідного масиву
	}

	std::map<int, int> freq_left, freq_right;  // Для підрахунку частот
	std::vector<int> left(n + 1), right(n + 1);

	// Створення дерева відрізків
	SegmentTree tree(n);

	// Підрахунок кількості появ елементів зліва
	for (int i = 1; i <= n; ++i) {
		left[i] = ++freq_left[a[i]];  // Кількість появ елемента a[i] з початку масиву
	}

	// Підрахунок кількості появ елементів справа
	for (int i = n; i >= 1; --i) {
		right[i] = ++freq_right[a[i]];  // Кількість появ елемента a[i] з кінця масиву
	}

	long long result = 0;

	// Використовуємо дерево відрізків для підрахунку пар
	for (int j = n; j >= 1; --j) {
		result += tree.query(1, 1, n, 1, left[j] - 1);  // Підраховуємо кількість пар
		tree.update(1, 1, n, right[j], 1);  // Оновлюємо дерево відрізків для елемента на позиції j
	}

	std::cout << result << std::endl;

	return 0;
}
