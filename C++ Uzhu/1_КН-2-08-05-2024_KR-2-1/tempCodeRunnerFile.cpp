#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> banderlogs(n);  
    for (int i = 0; i < n; i++) {
        std::cin >> banderlogs[i];
    }

   
    long long total_bananas = *std::min_element(banderlogs.begin(), banderlogs.end());

   
    //long long full_boxes = total_bananas / k; 
    //long long bananas_in_last_box = total_bananas % k; 

    std::cout << total_bananas % k << std::endl; 
    return 0;
}
