[169. Majority Element](https://leetcode.com/problems/majority-element/)

We can use voting algo here. Keep counting the current winner according to the current vote count. 

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner, winnerVoteCount = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(winnerVoteCount == 0) {
                winner = nums[i];
            }
            
            if(winner == nums[i]) {
                winnerVoteCount++;
            }
            else {
                winnerVoteCount--;
            }
        }
        
        return winner;
    }
};
```

> Time Complexity - O(N) </br>
> Space Complexity - O(1)