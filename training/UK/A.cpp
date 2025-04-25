 #pragma comment(linker, "/stack:200000000")
 #pragma GCC optimize("Ofast")
 #pragma GCC optimize("O3,unroll-loops")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")


#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int N;
	std::cin >> N;
	
	int win_type_1 = 0;  // Кількість виграшних позицій типу 1
	int win_type_2 = 0;  // Кількість виграшних позицій типу 2
	
	for (int i = 0; i < N; i++) {
		int register_value;
		std::cin >> register_value;
		
		int remainder = register_value % 5;
		if (remainder == 2 || remainder == 3) {
			win_type_1++;  // Це виграшна позиція 1 типу
		} else if (remainder == 4) {
			win_type_2++;  // Це виграшна позиція 2 типу
		}
	}
	
	// Якщо обидві кількості виграшних позицій парні, то програє перший гравець
	if (win_type_1 % 2 == 0 && win_type_2 % 2 == 0) {
		std::cout << "Watson" << std::endl;  // Виграє Ватсон
	} else {
		std::cout << "Rybka" << std::endl;   // Виграє Рибка
	}
	
	return 0;
}
