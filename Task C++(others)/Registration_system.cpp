#include <bits/stdc++.h>

using namespace std;
int n;
string a[100000];
int a1[100000],z;
int main()
{
   cin>>n;
   for (int i=0;i<n;i++)
	{ 
		cin>>a[i];
		z=0;
		for (int j=0;j<i;j++)
		{
			if (a[i]==a[j])
			{
            z=a1[j];
            a1[j]+=1;
				break;
			}
		}
		if (z==0) {cout<<"OK"<<endl;
		a1[i]++;}
		else cout<<a[i]<<z<<endl;
	}
}