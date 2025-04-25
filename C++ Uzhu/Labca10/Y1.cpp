#include <iostream>

void f(int n);

void del(int n){ 
   if(n > 0){
      del(n-2);
      std::cout<<-n<<" "; 
      f(n-2);
      del(n-1);
   }
}
void f(int n){ 
   if(n > 0){
      f(n-1);
      del(n-2);
      std::cout<<n<<" ";
      f(n-2);
   }
}
int main(){
   int n;
   std::cin>>n;
   f(n);
}