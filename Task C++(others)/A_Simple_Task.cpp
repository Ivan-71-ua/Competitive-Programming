#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

const int MAX_N = 100005;
const int MAX_TREE_SIZE = 400005;
const int ALPHABET_SIZE = 26;
const int MOD = 1000000007;

int tree[MAX_TREE_SIZE][ALPHABET_SIZE];  // Сегментне дерево для підрахунку кількості кожної букви
int lazy[MAX_TREE_SIZE][ALPHABET_SIZE];  // Ледаче оновлення для сегментного дерева
char s[MAX_N];  // Вхідна строка

// Побудова сегментного дерева
void build(int idx, int left, int right) {
	if (left == right) {
		tree[idx][s[left] - 'a'] = 1;  // Ініціалізація кількості букви
		for (int j = 0; j < ALPHABET_SIZE; j++) {
			lazy[idx][j] = -1;  // Ледаче оновлення ініціалізуємо як -1
		}
		return;
	}
	
	int mid = (left + right) / 2;
	build(2 * idx + 1, left, mid);  // Рекурсивно будуємо ліву частину
	build(2 * idx + 2, mid + 1, right);  // Рекурсивно будуємо праву частину
	
	for (int j = 0; j < ALPHABET_SIZE; j++) {
		lazy[idx][j] = -1;  // Ледачі оновлення
		tree[idx][j] = tree[2 * idx + 1][j] + tree[2 * idx + 2][j];  // Оновлюємо дерево
	}
}

// Ледаче оновлення дерева
void apply_lazy(int idx, int left, int right, int j) {
	if (lazy[idx][j] != -1) {
		tree[idx][j] = lazy[idx][j] * (right - left + 1);  // Оновлюємо дерево
		if (left != right) {
			lazy[2 * idx + 1][j] = lazy[idx][j];  // Пропагуємо ледачі оновлення на дочірні вузли
			lazy[2 * idx + 2][j] = lazy[idx][j];
		}
		lazy[idx][j] = -1;
	}
}

// Оновлення діапазону символів
void update(int idx, int left, int right, int query_left, int query_right, int val, int j) {
	apply_lazy(idx, left, right, j);
	
	if (left >= query_left && right <= query_right) {
		lazy[idx][j] = val;  // Застосовуємо ледачі оновлення
		apply_lazy(idx, left, right, j);  // Оновлюємо поточний вузол
		return;
	}
	
	if (left > query_right || right < query_left)
		return;
	
	int mid = (left + right) / 2;
	update(2 * idx + 1, left, mid, query_left, query_right, val, j);
	update(2 * idx + 2, mid + 1, right, query_left, query_right, val, j);
	
	tree[idx][j] = tree[2 * idx + 1][j] + tree[2 * idx + 2][j];  // Оновлюємо після рекурсії
}

// Запит на отримання кількості символів у діапазоні
int query(int idx, int left, int right, int query_left, int query_right, int j) {
	apply_lazy(idx, left, right, j);
	
	if (left >= query_left && right <= query_right)
		return tree[idx][j];
	
	if (left > query_right || right < query_left)
		return 0;
	
	int mid = (left + right) / 2;
	return query(2 * idx + 1, left, mid, query_left, query_right, j) + 
			query(2 * idx + 2, mid + 1, right, query_left, query_right, j);
}

// Функція для отримання результату після виконання всіх запитів
void get_result(int idx, int left, int right, int j) {
	apply_lazy(idx, left, right, j);
	
	if (!tree[idx][j])
		return;
	
	if (left == right) {
		s[left] = j + 'a';  // Записуємо результат в рядок
		return;
	}
	
	int mid = (left + right) / 2;
	get_result(2 * idx + 1, left, mid, j);
	get_result(2 * idx + 2, mid + 1, right, j);
}

int cnt[ALPHABET_SIZE];  // Підрахунок кожної літери

int main() {
	int n, q;
	std::cin >> n >> q;
	std::cin >> s;
	
	build(0, 0, n - 1);  // Побудова сегментного дерева
	
	for (int i = 0; i < q; i++) {
		int x, y, order;
		std::cin >> x >> y >> order;
		x--, y--;  // Зміщення до 0-індексу
		
		for (int j = 0; j < ALPHABET_SIZE; j++) {
			cnt[j] = query(0, 0, n - 1, x, y, j);  // Запит кількості символів
		}
		
		int curr = (order == 1) ? x : y;
		
		for (int j = 0; j < ALPHABET_SIZE; j++) {
			if (cnt[j] == 0) continue;
			
			update(0, 0, n - 1, x, y, 0, j);  // Очищаємо діапазон
			if (order == 1) {
				update(0, 0, n - 1, curr, curr + cnt[j] - 1, 1, j);  // Сортування по зростанню
				curr += cnt[j];
			} else {
				update(0, 0, n - 1, curr - cnt[j] + 1, curr, 1, j);  // Сортування по спадку
				curr -= cnt[j];
			}
		}
	}
	
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		get_result(0, 0, n - 1, i);  // Отримання кінцевого рядка
	}
	
	std::cout << s << '\n';
	
	return 0;
}
