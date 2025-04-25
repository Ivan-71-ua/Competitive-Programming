	#include <bits/stdc++.h>
	#define ll long long



int a,b,c,n,m,i,j,k,x,y,cnt=0,sum=0,res=0,mn;
void solve(){
	std::cin>>n>>k;
	std::vector<int> ar(n+1),vec(n+1);
	for(i=1;i<=n;i++){
		std::cin>>vec[i];
		ar[i]=ar[i-1]+vec[i];
	}
	mn=ar[k];
	for(i=k+1;i<=n;i++){
		if(ar[i]-ar[i-k]<mn){
			mn=ar[i]-ar[i-k];
			res=i-k;
		}
	}
	std::cout<<res+1;
}
main(){
	solve();
}