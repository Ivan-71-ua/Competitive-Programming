#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long n, a;
	cin >> n >> a;

	long long res = 0;
	long long end = a + n - 1;  // Останнє число для нумерації

	for (long long i = 1; i <= end; i *= 10) {
		long long start = max(a, i);  // Початок діапазону
		long long current_end = min(end, i * 10 - 1);  // Кінець діапазону
		
		if (start <= current_end) {
			res += (current_end - start + 1) * (long long)log10(i) + 1;
		}
	}

	cout << res << endl;

	return 0;
}
