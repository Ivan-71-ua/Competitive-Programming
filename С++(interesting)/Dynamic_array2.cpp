#include <bits/stdc++.h>
#include <memory>
using namespace std;






int main() {
	int size;
	std::cin >> size;
	shared_ptr<int[]> p(new int[size]{});
	for (int i = 0; i < size; i++)
	{
		p[i] = rand() % 100;
		std::cout << p[i] << ' ';
	}
	
	
}