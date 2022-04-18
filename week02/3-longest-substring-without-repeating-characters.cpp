// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Time Complexity - O(N)
// Memory Complexity - O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int len = s.length();
        int i = 0,j = 0;
        int ans = 0;
        
        while(i < len && j < len){
            if(mp[s[j]] == 0) {
                mp[s[j]]++;
                j++;
                ans = max(ans, j - i);
            }
            else {
                mp[s[i]] = 0;
                i++;
            }        
        }
        
        return ans;
    }
};