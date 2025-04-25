#include <bits/stdc++.h>
#define ll long long

namespace firstNS
{
	void Foo() {
		std::cout << "ALLLAALAA";
	}
}
namespace secondNS
{
	void Foo() {
		std::cout << "DUDADUDA";
	}
} 



int main() {
	firstNS::Foo();
	std::cout << std::endl;
	secondNS::Foo();
	std::cout << std::endl;
}