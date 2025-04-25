#include <iostream>
#include <string>

using namespace std;

// Функція для перевірки, чи є число паліндромом
bool is_palindrome(int a) {
	string s = to_string(a);
	int len = s.size();
	for(int i = 0; i < len / 2; i++) {
		if(s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}

void solve() {
	int n, max_palindrome = 0, factor1 = 0, factor2 = 0;
	cin >> n;
	
	// Перебираємо всі пари чисел від 1 до N-1
	for(int i = 1; i < n; i++) {
		for(int j = i; j < n; j++) {
			int product = i * j;
			
			// Якщо добуток є паліндромом і більше за поточний максимум
			if(is_palindrome(product) && product > max_palindrome) {
					max_palindrome = product;
					factor1 = i;
					factor2 = j;
			}
		}
	}
	
	// Виводимо пару множників
	cout << factor1 << " " << factor2 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();  // Викликаємо функцію розв'язку

	return 0;
}
