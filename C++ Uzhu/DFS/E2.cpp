#include <bits/stdc++.h>


void DFS(int k, std::vector<std::vector<int>> &v, std::vector<bool> &used, int &ver) {
	used[k] = true;
	for (auto now: v[k])
	{
			if(!used[now]) {
				ver++;
				DFS(now, v, used, ver);
		} 
	}
}

int main() {
	int n;
	int edg = 0;
	int ver = 1;
	std::cin >> n;
	std::vector<std::vector<int>> v(n);
	std::vector<bool> used(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			std::cin >> tmp;
			if(tmp == 1) {
				v[i].push_back(j);
				edg++;
			}
		}
	}
	
	DFS(0, v, used, ver);
	if(ver == n && edg / 2 == n - 1) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
}