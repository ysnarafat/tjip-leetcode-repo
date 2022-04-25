[238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int size = nums.size();
        vector<int> ans;
        ans.push_back(1);
        
        for(int i = 1; i < size; i++) {
            ans.push_back(ans.back() * nums[i-1]);
        }
                
        int suffixProd = 1;
        for(int i = size - 1; i >=0; i--) {
            ans[i] = ans[i] * suffixProd;
            suffixProd *= nums[i];
        }
        
        return ans;
    }
};
```

> Time Complexity - O(N) </br>
> Space Complexity - O(1) [Other than output array]