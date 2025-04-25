#include <bits/stdc++.h>


int main() {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	std::string text, word;
	std::cin >> text >> word;
	std::string temp = word;
	temp += "#" + text;
	std::vector <int> pip(temp.size(), 0);
   for (int i = 1; i < temp.size(); i++) {
      int j = pip[i - 1];
      while (j > 0 && temp[i] != temp[j]) {
         j = pip[j - 1];   
      }
      if(temp[i] == temp[j]) {
         j++;
         pip[i] = j;
      }
   }
	for (int i = 0; i < temp.size(); i++)
	{
		if(pip[i] == word.size())
			std::cout << i - (word.size() * 2) << " ";
	}
	
}
