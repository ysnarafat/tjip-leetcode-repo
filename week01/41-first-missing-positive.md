[41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/)

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        
        for(int i = 0; i < len; i++) {
            while(nums[i] >= 1 and nums[i] <= len and nums[i] != nums[nums[i] - 1]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        
        for(int i = 0; i < len; i++) {
            if(i + 1 != nums[i]) {
                return i + 1;
            }
        }
        
        return len + 1;
    }
};
```

> Time Complexity - O(N) </br>
> Space Complexity - O(1)