#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	for (int j = 0; j < n; j++)
	{
		std::string st;
		std::cin >> st;
		std::stack<char> way;
		bool is = true;
		for (int i = 0; i < st.size(); i++)
		{
			if(st[i] == '[' || st[i] == '(') {
				way.push(st[i]);
			} else {
				if(!way.empty() && st[i] == ']' && way.top() == '[') {
					way.pop();
				} else if(!way.empty() && st[i] == ')' && way.top() == '(') {
					way.pop();
				} else {
					is = false;
					break;
				}
			}
		}
        if(!way.empty())
            is = false;
		if(is) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}

}