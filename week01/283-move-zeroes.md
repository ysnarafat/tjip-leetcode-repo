[283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int bucketSize = nums.size();
        
        while(i < bucketSize && j < bucketSize) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
            
            i++;
        }
        
        for(int k = j; k < bucketSize; k++) {
            nums[k] = 0;
        }        
    }
};
```

> Time Complexity - O(N) </br>
> Space Complexity - O(1)