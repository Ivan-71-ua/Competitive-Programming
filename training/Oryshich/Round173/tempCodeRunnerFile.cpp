
int main() {
	int t;
	cin >> t;
	while (t--) {
		ll l, r, G;
		cin >> l >> r >> G;

		// Масштабуємо межі
		ll l_prime = (l + G - 1) / G; // l' = ceil(l / G)
		ll r_prime = r / G;           // r' = floor(r / G)

		// Перебір пар x, y
		for (ll i = r_prime - l_prime; i >= 0; i--) { // i = y - x
			for (ll j = l_prime; j + i <= r_prime; j++) { // x = j
				if (__gcd(j, j + i) == 1) { // Перевірка НОД(x, y) = 1
					cout << j * G << " " << (j + i) * G << endl;
					return 0;
				}
			}
		}

		// Якщо пари не знайдено
		cout << "-1 -1" << endl;
	}
	return 0;
}