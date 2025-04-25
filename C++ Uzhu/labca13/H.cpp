#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int HROZNY(std::vector<int> &vec) {
	for (int i = 1; i < vec.size(); i++)
		if (vec[i] < i) return i - 1;
	return vec.size() - 1;
}

int main() {
	int t, k;
	std::cin >> t >> k;
	std::vector<int> vec(t +1);
	for (int i = 1; i < t + 1; i++)
	{
		std::cin >> vec[i];
	}
	std::sort(vec.begin() + 1, vec.end(), std::greater());
	int tmp = HROZNY(vec);
	for (int i = tmp + 1; i  > std::max(tmp - k +1,0); i--)
	{
		vec[i]++;
	}
	std::sort(vec.begin() + 1, vec.end(), std::greater());
	std::cout << HROZNY(vec);
}