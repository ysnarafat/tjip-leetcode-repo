[1. Two Sum](https://leetcode.com/problems/two-sum/)


```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> bucket;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            if(bucket.find(target - nums[i]) != bucket.end()) {
                ans.push_back(i);
                ans.push_back(bucket[target - nums[i]]);
            }
            
            bucket[nums[i]] = i;
        }   
                          
        return ans;
    }
};
```

> Time Complexity - O(N) </br>
> Space Complexity - O(N) 