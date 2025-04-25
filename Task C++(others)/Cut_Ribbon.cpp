#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,c;
	int t=0;
	cin>>n>>a>>b>>c;
	
	for(int i=0;i<=n;i+=a){
		for(int j=0;i+j<=n;j+=b){
			if((n-i-j)%c==0&&(n-i-j)/c+i/a+j/b>t){
				t=(n-i-j)/c+i/a+j/b;
			}
		}
	}
	cout<<t<<endl;

}