#include <bits/stdc++.h>
#define ll long long

template <typename T>
class Printer{
public:
	void Print(T val) {
		std::cout << val << "\n";
	}
};

template <>
class Printer<std::string> {
public:
	void Print(std::string val) {
		std::cout << "+++ " << val << " +++\n";
	}
};

int main() {
	Printer<int> p;
	p.Print(2323);
	Printer<std::string> l;
	l.Print("Hrozny");
}