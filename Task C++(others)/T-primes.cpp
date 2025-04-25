#include<bits/stdc++.h>
#include<cmath>
#include<string.h>
using namespace std;
#define ll long long int
 
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
int main() {
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<string>v;
	for(ll i=0;i<n;i++){
		
		if((ll)sqrt(arr[i])*(ll)sqrt(arr[i])!=arr[i]){
			v.push_back("NO");
		}
		else if((ll)sqrt(arr[i])*(ll)sqrt(arr[i])==arr[i] && isPrime((ll)sqrt(arr[i]))){
			v.push_back("YES");
		}
		else{
			v.push_back("NO");
		}
	}
	for(ll i=0;i<n;i++){
		cout<<v[i]<<endl;
	}
}