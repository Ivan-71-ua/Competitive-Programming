#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>


const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 9;
const int SZ = 770;  // Поріг для частоти оновлення масиву `add`

// Масиви для збереження даних
int a[MAXN], add[MAXN], fib[MAXN], preFib[MAXN], preSum[MAXN];
int n, m;

// Функція для попереднього обчислення чисел Фібоначчі, префіксних сум і префіксних чисел Фібоначчі
void preset() {
	fib[1] = 1;
	fib[2] = 1;
	preFib[1] = 1;
	preFib[2] = 2;
	preSum[1] = a[1];
	preSum[2] = (a[1] + a[2]) % MOD;

	// Обчислюємо всі числа Фібоначчі, префіксні числа Фібоначчі та префіксні суми для всіх елементів масиву
	for (int i = 3; i < MAXN; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
		preFib[i] = (preFib[i - 1] + fib[i]) % MOD;
		preSum[i] = (preSum[i - 1] + a[i]) % MOD;
	}
}

// Вектор для збереження запитів на оновлення
std::vector<std::pair<int, int>> upd;

// Функція для накопичення оновлень, щоб уникнути їх частого виконання
void update() {
	upd.clear();  // Очищуємо запити
	for (int i = 1; i <= n; i++) {
		// Накопичуємо значення для кожного елемента
		add[i] = (add[i] + add[i - 1]) % MOD;
		if (i > 1) {
			add[i] = (add[i] + add[i - 2]) % MOD;
		}
		// Оновлюємо масив `a` з урахуванням накопичених додатків
		a[i] = (a[i] + add[i]) % MOD;
		// Оновлюємо префіксні суми
		preSum[i] = (preSum[i - 1] + a[i]) % MOD;
	}
	// Скидаємо масив `add`
	memset(add, 0, sizeof(add));
}

// Функція для підготовки оновлення на відрізку [l, r]
void prepare(int l, int r) {
	upd.push_back({l, r});  // Зберігаємо запит на оновлення
	(add[l] += 1) %= MOD;   // Додаємо 1 до початку відрізка
	(add[r + 1] -= fib[r - l + 2]) %= MOD;  // Віднімаємо відповідне число Фібоначчі після кінця відрізка
	(add[r + 2] -= fib[r - l + 1]) %= MOD;  // Віднімаємо ще одне число Фібоначчі
}

// Функція для обчислення суми на відрізку [l, r]
int query(int l, int r) {
	int value = (preSum[r] - preSum[l - 1] + MOD) % MOD;  // Визначаємо початкову суму на відрізку
	// Проходимо по всіх запитах на оновлення і коригуємо результат
	for (auto pending : upd) {
		int t1 = std::max(l, pending.first);
		int t2 = std::min(r, pending.second);
		if (t1 > t2) continue;  // Якщо немає перетину відрізків, пропускаємо

		// Коригуємо суму з використанням префіксних чисел Фібоначчі
		int p1 = t1 - pending.first + 1;
		int p2 = t2 - pending.first + 1;
		value = (value + preFib[p2] - preFib[p1 - 1]) % MOD;
	}
	return (value % MOD + MOD) % MOD;  // Повертаємо результат з модулем
}

int main() {

	// Введення даних
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	// Попередньо обчислюємо числа Фібоначчі та префіксні суми
	preset();

	// Обробляємо кожен запит
	for (int i = 1; i <= m; i++) {
		int t, l, r;
		std::cin >> t >> l >> r;
		if (t == 1) {
			// Якщо це запит на оновлення
			prepare(l, r);
		} else {
			// Якщо це запит на отримання суми
			std::cout << query(l, r) << '\n';
		}
		// Оновлюємо масив кожні SZ запитів, щоб уникнути переповнення
		if (i % SZ == 0) {
			update();
		}
	}
	return 0;
}
