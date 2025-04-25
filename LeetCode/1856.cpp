#include <bits/stdc++.h>

class Solution {
public:
    int maxSumMinProduct(std::vector<int>& arr) {
        
        int n = arr.size();
        
        long long mod = 1e9 + 7;
        
        // find the prefix sum
        
        std::vector<long long> prefix(n, 0);
        
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        // declare a stack
        
        std::stack<int> st;
        
        // find the index of next smaller element on left side
        
        std::vector<int> left(n, -1);
        
        std::vector<int> right(n, n);
        
        for(int i = 0; i < n; i++)
        {
            while(st.empty() == false && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = st.top();
            }
            
            st.push(i);
        }
        
        // empty stack
        
        while(st.empty() == false)
        {
            st.pop();
        }
        
        // find the next smaller element on right side
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(st.empty() == false && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                right[i] = n;
            }
            else
            {
                right[i] = st.top();
            }
            
            st.push(i);
        }
        
        // calculate maximum min-product 
       
        long long max_sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            long long sum = 0;
            
            sum += prefix[right[i] - 1];
            
            if(left[i] >= 0)
            {
                sum -= prefix[left[i]];
            }
            
            sum *= arr[i];
            
            max_sum = std::max(max_sum, sum);
        }
        
        return max_sum % mod;
    }
};

int main() {
	Solution ans;
	std::vector<int> nums{2, 3, 3, 1,2};
	ans.maxSumMinProduct(nums);
}