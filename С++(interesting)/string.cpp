
#include<bits/stdc++.h>

using namespace std;

int fib(int n, std::vector<int> memoization) {
	if(n < 0) return 0;
	if(n < 3) return 1;
	if(memoization[n] != -1) return memoization[n];
	memoization[n] = fib(n -1, memoization) + fib(n - 2, memoization);
	return  memoization[n];
}

int main()
{
	int n;
	cin >> n;
	std::vector<int> memoization(n + 1, -1);
	std::cout << fib(n, memoization);
}