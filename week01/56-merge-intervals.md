[56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)

Update the resultant list according to the current best value after sorting of input <b>intervals</b> will work.

```cpp
class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortcol);
        vector<vector<int>> ans;
        
        if(intervals.size() == 0) {
            return ans;
        }
        
        ans.push_back(intervals[0]);
        
        int i = 0, j = 1;
        
            while(j < intervals.size()) {
                if(ans[i][1] >= intervals[j][0]) {
                    ans[i][1] = max(ans[i][1], intervals[j][1]);
                }
                else {
                    ans.push_back(intervals[j]);
                    i++;
                }
                j++;                
            }
        
        return ans;
    }    
};
```

> Time Complexity - O(NLogN) </br>
> Space Complexity - O(N)