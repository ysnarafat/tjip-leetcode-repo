// https://leetcode.com/problems/valid-anagram/

// Time Complexity - O(|s| + |t|) --> O(N)
// Memory Complexity - O(N)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> mp;
        
        for(char ch : s) {
            mp[ch]++;
        }
        
        for(char ch : t) {
            mp[ch]--;
            
            if(mp[ch] < 0) {
                return false;
            }
        }
        
        return true;
    }
};