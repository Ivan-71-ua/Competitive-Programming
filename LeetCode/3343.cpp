
#include <bits/stdc++.h>



class Solution {
public:
	static const int mod = 1e9 + 7;
	std::vector<long long> fact, invFact;
	void precompute(int n) {
		fact.resize(n + 1, 1);
		invFact.resize(n + 1, 1);
		
		// Обчислення факторіалів
		for (int i = 2; i <= n; i++) {
			fact[i] = fact[i - 1] * i % mod;
		}
		
		// Обчислення інверсій факторіалів
		invFact[n] = modInverse(fact[n]);
		for (int i = n - 1; i >= 0; i--) {
			invFact[i] = invFact[i + 1] * (i + 1) % mod;
		}
	}
	// Функція для знаходження модульної інверсії
	long long modInverse(long long a) {
		return power(a, mod - 2); // за теоремою Ферма
	}
	// Функція для піднесення до степеня по модулю
	long long power(long long a, long long b) {
		long long result = 1;
		while (b) {
			if (b % 2) result = result * a % mod;
			a = a * a % mod;
			b /= 2;
		}
		return result;
	}

	int countBalancedPermutations(std::string& s) {
		int n = s.size();
		int sum = 0;
		for (char c : s) sum += c - '0';  // Сума всіх цифр
		if (sum % 2 == 1) return 0;  // Якщо сума непарна, не можна розділити на рівні частини
		precompute(n);  // Обчислюємо факторіали та їх інверсії
		int halfSum = sum / 2, halfLen = n / 2;
		std::vector<std::vector<long long>> dp(halfSum + 1, std::vector<long long>(halfLen + 1, 0));
		dp[0][0] = 1;  // Початкове значення для dp
		std::vector<int> digits(10, 0);
		for (char c : s) {
			int digit = c - '0';
			digits[digit]++;
			// Оновлення dp для кожної цифри
			for (int i = halfSum; i >= digit; i--) {
				for (int j = halfLen; j > 0; j--) {
					dp[i][j] = (dp[i][j] + dp[i - digit][j - 1]) % mod;
				}
			}
		}
		// Розрахунок результату
		long long result = dp[halfSum][halfLen];
		result = result * fact[halfLen] % mod * fact[n - halfLen] % mod;
		// Врахування повторів цифр
		for (int i : digits) {
			result = result * invFact[i] % mod;
		}
		return result;
	}
};
