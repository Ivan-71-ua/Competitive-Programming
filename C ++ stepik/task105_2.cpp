#include <iostream>
#include <map>
#include <set>
#include <string> 

using namespace std;

int main() {
	map <string, set <string>> a; //будущий словарь
	string s,eng;
	int n,i;
	cin >> n;
	getline(cin, s); //просто перенос на следующею строку
    
	for (int j = 0; j < n; j++) {
		getline(cin, s); 
        eng = s.substr(0, s.find(' ')); //выделяем из строки английское слово
		s = s.substr(s.find('-') + 2, s.size() - 1); //оставляем в строке только латинские слова
		
        i = s.find(','); 
		while (i > 0) { //для каждого латинского слова создаём запись в словаре и добавляем туда eng 
			a[s.substr(0, i)].insert(eng);
			s = s.substr(i + 2, s.size() - 1);
			i = s.find(',');
		}
		a[s].insert(eng);
        
        
	}
	cout << a.size() << "\n"; //вывод
	for (auto c : a) {
		i = 1;
		cout << c.first << " - ";
		for (auto lat : c.second) {
			cout << lat;
			if (i != c.second.size()) {cout << ", "; }
			else { cout << "\n"; }
			i++;
		}
	}
	return 0;
}