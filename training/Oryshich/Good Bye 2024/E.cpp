


#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		vector<vector<int>> a(n + 2);
		for(int i=0;i<=n+1;++i)
			a[i] = vector<int>(m + 1);
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
			cin >> a[i][j];
		vector<map<int, int>> d(n + 2);
		vector<int> c(n + 2);
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
			++(a[i][j] == -1 ? c[i] : d[i][a[i][j]]);
		long long s = 0;
		for(int i = 2;i <= n; ++i)
		{
			s += (long long)c[i - 1] * c[i];
			for(const auto&j:d[i-1])
			{
				const auto tmp = d[i].find(j.first);
				if (tmp != d[i].end())
					s += (long long)j.second * tmp->second;
			}
		}
		for(int i=0;i<n;++i)
			for(const auto&j:d[i+2])
				d[i][j.first] += j.second;
		vector<long long>mx(n+1),f(k+1);
		long long u = 0;
		for(int i=1;i<=n;++i)
		{
			mx[i] = mx[i - 1];
			for(const auto&j:d[i-1])
				mx[i] = max(mx[i], f[j.first] = max(max(f[j.first], u) + (long long)j.second * c[i], 
				mx[i - 1] + (long long)(j.second - c[i - 1]) * c[i]));
			u = max(u, mx[i - 1] - (long long)c[i - 1] * c[i]);
		}
		cout << mx[n] + s << '\n';
	}
	return 0;
}