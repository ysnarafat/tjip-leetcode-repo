// https://leetcode.com/problems/4sum-ii/

// Time Complexity - O(N^2) --> N = size of each number array 
// Memory Complexity - O(N) 

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> bucket;              
        
        for(auto num3 : nums3) 
            for(auto num4 : nums4) {
                bucket[num3 + num4]++;
            }
        
        int tuplesCount = 0;
        
        for(auto num1 : nums1) 
            for(auto num2 : nums2) {
                if(bucket.count(-(num1 + num2)) >= 1) {
                    tuplesCount += bucket[-(num1 + num2)];
                }
            }
        
        return tuplesCount;
    }
};