#include <bits/stdc++.h>
using namespace std;


int main(void)

{
	string s;
	char s1, s2;
   cin >> s >> s1 >> s2;
   replace(s.begin(),s.end(),s1,s2);
   while(s[0] == '0')  {
		s.erase(s.begin());
	}
   if (s.size() == 0) s = "0";
   cout << s << endl;
}