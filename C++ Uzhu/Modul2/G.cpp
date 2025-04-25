#include <bits/stdc++.h>
#define ll long long

void gen(std::string s, int left, int right)
{
	if (left == 0 && right == 0)
	{
		std::cout << s << '\n';
		return;
	}
	if (left > 0)     gen(s + "(", left - 1, right);
	if (left < right) gen(s + ")", left, right - 1);

}

int main() {
	int n;
	std::cin >> n;
	gen("", n, n);
}