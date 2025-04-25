#include <bits/stdc++.h>
#define int long long
int search(std::vector<int> &arr, int x) {
    int start = 0;
    int end = arr.size() -1;
    while(start < end) {
        int mid1 = start + (end - start) / 3;
        int mid2 = end - (end - start) / 3;
        if (x == arr[mid1]) return 1;
        if (x == arr[mid2]) return 1;
        if (x < arr[mid1])
            end = mid1 - 1;
        else if (x < arr[mid2])
        {
            start = mid1 + 1;
            end = mid2 - 1;
        }
        else
            start = mid2 + 1;
    }
    return x == arr[start];
}


int32_t main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        if(search(arr, x)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}