#include <bits/stdc++.h>


int main() {
	std::vector<std::stack<int>> sk;
	sk.push_back(std::stack<int>());
	std::unordered_map<int, int> quant;
	std::string ss;
	while (std::cin >> ss)
	{
		if(ss == "push") {
			int n;
			std::cin >> n;
			quant[n]++;
			if(quant[n] == sk.size())
				sk.push_back(std::stack<int>());
			sk[quant[n]].push(n);
		} else {
			std::cout << sk.back().top() << '\n';
			quant[sk.back().top()]--;
			sk.back().pop();
			if(sk.back().empty())
				sk.pop_back();
		}
	}
}