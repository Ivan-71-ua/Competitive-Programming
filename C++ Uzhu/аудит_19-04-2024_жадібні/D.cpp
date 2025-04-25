#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	int sim = 0;
	int not_sim = 0;
	for (int i = 0; i < n; i++)
	{
		int g;
		std::cin >> g;
		if(g % 2 == 0)
			not_sim++;
		else
			sim++;
	}
	while(sim > not_sim) {
		sim -= 2;
		not_sim++;
	}
	if(not_sim > sim +1)
		not_sim = sim + 1;
	std::cout << sim + not_sim;
}