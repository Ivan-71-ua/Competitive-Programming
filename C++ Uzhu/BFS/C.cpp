#include <bits/stdc++.h>
#define int long long

int BFS(int x, int y, int a, int b) {
	int res = 0;
	std::unordered_set<int> way;
	way.insert(x);
	while(true) {
		if(res >= INT32_MAX)
			return -1;
		std::unordered_set<int> cur;
		for (auto now: way)
		{
				if(now == y)
					return res;
				else{
					if(now - b > -1)
						cur.insert(now - b);
					cur.insert(now + a);
				}
		}
		res++;
		way = cur;
	}
}


int32_t main() {
	int x, y, a, b;
	std::cin >> x >> y >> a >> b;
	if(a == b && (y - x) % a != 0)
		std::cout << -1;
	else if((y -x) % a == 0)
		std::cout << (y - x) / a;
	else {
		std::cout << BFS(x, y, a, b);
	}
}
