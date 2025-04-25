#include <iostream>
#define ll long long


int main() {
int n;
   std::cin>>n;
	ll j=1;
	for (int i=1; i<n; i++)
	j=j*i;
	std::cout<<2*j/n;
}