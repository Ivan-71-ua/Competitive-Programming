#include <bits/stdc++.h>


int find_max_range(std::vector<int> arr) {
    int n = arr.size();
    std::vector<int> pref(n);
    pref[0] = arr[0];
    for (int i =1; i < n; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
    }
    int maxs = arr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++) {
            maxs = std::max(maxs, pref[i] - (j == 0 ? 0 : pref[j - 1]));
        }
    }
    return maxs;
}

int find_max_range2(std::vector<int> arr) {
    int n = arr.size();
    int maxs = arr[0];
    int cur_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_sum += arr[i];
        maxs = std::max(maxs, cur_sum);
        if (cur_sum < 0) cur_sum = 0; 
    }
    return maxs;
}

int find_max_range3(std::vector<int> arr) {
    int n = arr.size();
    int maxs = arr[0];
    int pref_r = arr[0];
    int min_pref_l = 0;
    for (int i = 1; i < n; i++) {
        pref_r += arr[i];
        min_pref_l = std::min(min_pref_l, pref_r);
        maxs = std::max(maxs, pref_r - min_pref_l);
        
    }
    return maxs;
}





int main()
{
    std::vector<int> ss{ -6, -5,4,-4,-4,-4,-4,-4 };
    std::cout << find_max_range3(ss);
}