#include <bits/stdc++.h>
#define ll long long

int main() {
	std::string a, b;
	std::cin >> a >> b;
	bool ans = true;
	for (int i = 0; i < b.size(); i++)
	{
		if(std::count(b.begin(),b.end(), b[i]) <= std::count(a.begin(),a.end(), b[i])) {
			continue;;
		}
		else {
			ans = false;
		}
	}
	if(ans) {
		std::cout << "Ok";
	}
	else{
		std::cout << "No";
	}
	
}