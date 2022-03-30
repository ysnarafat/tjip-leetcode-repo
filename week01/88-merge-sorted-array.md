[88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

Inserting into the last elements of the nums1 will reduce the swapping overhead. 

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;

        m = m - 1;
        n = n - 1;	
        
        while(m >= 0 && n >= 0) {
            if(nums1[m] < nums2[n]) {
                nums1[index] = nums2[n];
                n--;
            }
            else {
                nums1[index] = nums1[m];
                m--;
            }

            index--;
        }
        
        while(n >= 0) {
            nums1[index] = nums2[n];
            n--;
            index--;
        }
    }
};
```

> Time Complexity - O(N) </br>
> Space Complexity - O(1)