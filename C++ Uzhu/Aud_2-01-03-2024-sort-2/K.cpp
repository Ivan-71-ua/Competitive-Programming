#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int n;
void run(std::vector<int>& bread, int pos) {
	int v;
	while(bread[pos] != -1) {
		v = bread[pos];
		bread[pos] = -1;
		pos = v;
	}
}

int parity(std::vector<int>& bread) {
   int res = 0;
   for(int i = 0; i < n; i++) {
      if (bread[i] != -1) {
         run(bread, i);
         res++;
      }
   }
   return res % 2;
}

int main() {
	fast;
	std::cin >> n;
	std::vector<int> bread(n);
	for(int i = 0; i < n; i++) {
		std::cin >> bread[i];
		bread[i]--;
	}
	int tmp1 = parity(bread);
	for(int i = 0; i < n; i++) {
		std::cin >> bread[i];
		bread[i]--;
	}
	int tmp2 = parity(bread);
	if (tmp1 == tmp2) std::cout << "Possible" << std::endl;
	else std::cout << "Impossible" << std::endl;
}