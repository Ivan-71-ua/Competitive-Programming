#include <bits/stdc++.h>


void HROZNY(){
   long long n,m; 
	std::cin >> n >> m;
   long long mat[n][m];
   for (int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         std::cin >> mat[i][j];
      }
   }
   long long k, ans = 0; 
	std::cin >> k;
   while (k--){
      long long y1,y2,x1,x2;
      std::cin >> y1 >> y2 >> x1 >> x2;
      for(int y = y1 - 1; y < y2; y++){
         for (int x = x1 - 1; x <x2; x++){
            ans += mat[y][x];
            mat[y][x] = 0;
         }
      }
   }
   std::cout << ans;
}

int main() {
	HROZNY();
}