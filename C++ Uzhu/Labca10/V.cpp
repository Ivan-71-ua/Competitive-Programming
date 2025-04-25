#include <bits/stdc++.h>

void hanoi(int n, int from, int to, int additional)
{
	if (n == 0) return;
	hanoi(n-1,from,additional,to);
	std::cout << from << ' ' << to << '\n'; 
	hanoi(n-1,additional,to,from);
}

int main() {
	int n;
	std::cin >> n;
	hanoi(n, 1, 2, 3);
}