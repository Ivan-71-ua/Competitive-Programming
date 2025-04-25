#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    char arr[n + 2][m +2];
    int count = 0;
    for (int i = 0; i < n+2; i++)
    {
        for (int j = 0; j < m  + 2; j++) {
            arr[i][j] = '#';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) {
            if(arr[i][j] == '#') continue;
            else if(arr[i][j] == '?') {
                if(arr[i +1][j] == '#' && arr[i -1][j] == '#' && arr[i][j +1] == '#' && arr[i][j-1] == '#') {
                    arr[i][j] = '#';
                }
                else {
                    arr[i][j] = '.';
                }
            } else {
                count++;
                int k = i, p = j;
                int k1 = i, p1 = j;
                while(arr[k +1][j] != '#') {
                    arr[k][j] = '#';
                    k++;
                }
					 arr[k][j] = '#';
					 while(arr[k1 -1][j] != '#') {
                    arr[k1][j] = '#';
                    k1--;
                }
					 arr[k1][j] = '#';
                while(arr[i][p  +1] != '#') {
                    arr[i][p] = '#';
                    p++;
                }
					arr[i][p] = '#';
                while(arr[i][p1 - 1] != '#') {
                    arr[i][p1] = '#';
                    p1--;
                }
					arr[i][p1] = '#';
            }
        }
    }
    cout << count;
}
