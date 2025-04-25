#include <bits/stdc++.h>

int main(){
	std::stack<int> tmp;
	std::string ss;
	while(std::cin >> ss) {
		if(ss == "push") {
			int n;
			std::cin >> n;
			tmp.push(n);
			std::cout << "ok\n";
		} else if(ss == "pop") {
			std::cout << tmp.top() << '\n';
			tmp.pop();
		} else if(ss == "size") {
			std::cout << tmp.size() << '\n';
		} else if(ss == "clear") {
			std::cout << "ok\n";
			std::stack<int> k;
			tmp = k;
		} else if(ss == "back") {
            std::cout << tmp.top() << '\n';
      } else if(ss == "exit") {
			std::cout << "bye\n";
			break;
		}
	}
}