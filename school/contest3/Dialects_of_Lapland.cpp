#include <bits/stdc++.h>


int main() {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);
	std::map<std::string, std::string> elf_eng;
	std::string elfic, english;
	while(std::cin >> elfic && std::cin >> english && elfic != "dictionary" && english != "finished") {
		if(elf_eng.count(elfic)) {
			if(elf_eng[elfic] == english)
				std::cout << "your translation is correct" << std::endl;
			else {
				std::cout << "your translation is incorrect" << std::endl;
			}
		} else {
			elf_eng[elfic] = english;
			std::cout << "your translation has been added successfully" << std::endl;
		}
	}
	std::cout << elf_eng.size() << std::endl;
	for (auto now: elf_eng)
	{
		std::cout << now.first << ' ' << now.second << std::endl;
	}
	
}
