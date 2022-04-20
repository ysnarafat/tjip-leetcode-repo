// https://leetcode.com/problems/group-anagrams/

// Time Complexity - O(N * K) --> N = size of the string array, K = size of each string
// Memory Complexity - O(N)

class Solution {
public:
    unsigned long long getHashValue(string s) {
        unsigned long long hashValue = 1;
        
        for (char c : s) {
            hashValue = (hashValue * (c - 'a' + 257));
        }
        
        return hashValue;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<unsigned long long, vector<string>> anagrams;        
        vector<vector<string>> groupedAnagrams;
        
        for(auto str : strs) {
            anagrams[getHashValue(str)].push_back(str);
        }
        
        for(auto anagram : anagrams) {
            groupedAnagrams.push_back(anagram.second);
        }
        
        return groupedAnagrams;
    }
};