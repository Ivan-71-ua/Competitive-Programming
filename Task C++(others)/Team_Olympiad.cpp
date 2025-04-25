#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
 
int main() {
    int arr[3] = { 0 };
    int t;
    cin >> t;
    unordered_map<int, vector<int>> index;
    int x, cnt = 1;
    for (int i = 0; i < t; i++)
    {
        cin >> x;
        arr[x-1]++;
        index[x].push_back(cnt);
        cnt++;
    }
    int min = *min_element(arr, arr + 3);
    cout << min << endl;
    for (int i = 0; i < min; i++)
    {
        for (int j = 1; j <= 3; j++) {
        
            cout << index[j][i] << " ";
        }
 
        cout << endl;
    }
    return 0;
}