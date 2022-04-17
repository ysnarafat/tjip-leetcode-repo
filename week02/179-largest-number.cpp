// https://leetcode.com/problems/largest-number/

// Time Complexity - O(N * LogN)
// Memory Complexity - O(N)

class Solution {
public:
    static bool comp(int a, int b) {        
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string result;
        
        for(auto a: nums) {
            result += to_string(a);
        }
        
        return result[0] == '0' ? "0" : result;
    }
};