[136. Single Number](https://leetcode.com/problems/single-number/)

After doing XOR operation on the elements similiar elements will cancel out themselves. Only the unique one remains at the end. 

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleElement = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            singleElement = singleElement ^ nums[i];
        }
        
        return singleElement;
    }
};
```

> Time Complexity - O(N) </br>
> Space Complexity - O(1)