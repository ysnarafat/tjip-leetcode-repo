[215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int num : nums) {
            pq.push(num);
        }
        
        int ans;
        
        while(!pq.empty()) {
            if(pq.size() == k) {
                ans = pq.top();
            }
            
            pq.pop();
        }
        
        return ans;
    }
};
```

> Time Complexity - O(LogN) [For push and pop] </br>
> Space Complexity - O(N) [Other than output array]