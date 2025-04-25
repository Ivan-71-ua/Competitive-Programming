#include <bits/stdc++.h>
using namespace std;


int str() {
	std :: string s, l = "#$%!&'()*+,-./:;<=]>?@[^_`{|}~";
	getline(std::cin, s);
	int k = 0;
	for(int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < l.size(); j++) {
			if(s[i] == l[j]) {
				k++;
			}
		}
			if (s[i] == '"' || s[i] == 92)
			{
				k++;
			}
	}
	return k;
}

int main() {
	std::cout << str();
}