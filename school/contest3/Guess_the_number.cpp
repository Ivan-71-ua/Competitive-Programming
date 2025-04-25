#include <bits/stdc++.h>


int main() {
   int n;
   std::cin>>n;
   int l=1, r=n+1;
   while(r-1>l){
      int mid = (l + r) / 2 ;
      std::cout << mid << std::endl;
      std::string ans;
      std::cin >> ans;
      if(ans == ">="){
         l = mid; 
      }else if(ans == "<"){
         r = mid;
      }
   }
   std::cout << "! "<< l << std::endl;
}