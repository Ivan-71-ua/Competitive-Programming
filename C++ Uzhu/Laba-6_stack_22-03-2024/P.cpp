#include <bits/stdc++.h>

int main(){
	std::stack<int> tmp;
	std::string ss;
	while(std::cin >> ss) {
		if(ss == "push") {
			int n;
			std::cin >> n;
			tmp.push(n);
		} else if(ss == "pop") {
			if(!tmp.empty()) {
				tmp.pop();
			} 
		} else if(ss == "top") {
			if(!tmp.empty()) {
				std::cout << tmp.top() << '\n';
			}
		}
	}
}