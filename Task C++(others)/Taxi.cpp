#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,sum=0,count=0,x=0,y=0,z=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==4) count++;
        if(arr[i]==3) x++;
        if(arr[i]==2) y++;
        if(arr[i]==1) z++;
    }
    if(z<=x)
    {
        sum=sum+x;
        z=0;
    }
    else{
        sum=sum+x;
        z-=x;
    }
 

    if(y%2==0)
    {
        sum=sum+y/2;
        y=0;
    }
    else{
        sum=sum+y/2+1;
        z=z-2;
    }

    if(z>0)
    {
        if(z%4==0)
        {
            sum=sum+z/4;
        }
        else
        {
            sum+=z/4+1;
        }
    }

    sum=sum+count;
    cout<<sum;
}