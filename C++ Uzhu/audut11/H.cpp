#include <bits/stdc++.h>
#define ll long long


int main(){ int n; 
	std::cin>>n; 
	int arr[n]; 
	arr[0]=2; 
	arr[1]=4; 
	arr[2]=7; 
	for(int i=3; i<n; i++) 
		arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%12345; 
	std::cout<<arr[n-1]; 
}
