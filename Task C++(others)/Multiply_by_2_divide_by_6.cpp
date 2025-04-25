#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   int t;
   cin>>t;
   while(t--){
      ll n;
      cin>>n;
      ll s1 = 0 , s2 = 0;
      while(n%2 == 0)
      {
         s1++;
         n/=2;
      }
      while(n%3 == 0)
      {
         s2++;
         n/=3;
      }
      if(n == 1)
      {
         if(s1 <= s2)
         {
            ll ans = min(s1,s2);
            s1-=ans;
            s2-=ans;
            ans += s2*2;
            cout<<ans<<"\n";
         }   
         else{
            cout<<"-1\n";
         }
      }
      else
			cout<<"-1\n";
   }
}