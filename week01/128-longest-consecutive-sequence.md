[128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)


```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> bucket(nums.begin(), nums.end()); 
        int longConSeq = 0;
        
        for(auto value : bucket) {
            if(bucket.count(value - 1) == 0) {
                int currentValue = value;
                
                while(bucket.count(currentValue)) {
                    currentValue++;
                }
                
                longConSeq = max(longConSeq, currentValue - value);
            }
        }
        
        return longConSeq;
    }
};
```

> Time Complexity - O(N) </br>
> Space Complexity - O(N)