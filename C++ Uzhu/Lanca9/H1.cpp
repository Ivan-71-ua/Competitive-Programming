#include<bits/stdc++.h>
using namespace std;

void Foo() {
	multiset<int> m; 
	set<int> t; 
	int p,l=2; 
	cin>>p; 
	while(p/l!=0){ 
		while(p%l==0 and p!=0){ 
			m.insert(l); 
			t.insert(l); p/=l; 
		} 
		l++; 
	} 
	int k=0; 
	for(auto i :t){ 
		k++; cout<<i; 
		if(m.count(i)!=1) cout<<'^'<<m.count(i); 
		if(k==t.size()) break; else cout<<'*'; 
		} 
}

int main(){
	Foo();
}