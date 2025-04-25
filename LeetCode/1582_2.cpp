#include <bits/stdc++.h>

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),c=0;
        std::vector<int> rowZ(m,0);
        std::vector<int> colZ(n,0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (mat[i][j] == 0) {
                    rowZ[i]++;
                    colZ[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(mat[i][j]==1 && rowZ[i]==n-1  && colZ[j]==m-1) c++;
        }
        return c;
        
    }
};

int main() {
	Solution ans;
	std::vector<std::vector<int>>  mat {{1,0,0}, {0,1,0}, {0,0,1}};
	std::cout << ans.numSpecial(mat);
}