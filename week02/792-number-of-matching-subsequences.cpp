// https://leetcode.com/problems/number-of-matching-subsequences/

// Time Complexity - O(N * K * Log(M)) --> N = size of the string array, K = size of each string, M = binary search space 
// Memory Complexity - O(N)

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        int len = s.length();        
        int subSeqCount = 0;
        
        for(int i = 0; i < len; i++) {
            mp[s[i]].push_back(i);    
        }
        
        bool isSubSeq = false;
        
        for(auto word : words) {            
            int pos = -1;
            isSubSeq = true;
            
            for(auto ch : word) {               
                vector<int>::iterator it = upper_bound(mp[ch].begin(), mp[ch].end(), pos);
                    
                if(it == mp[ch].end()) {
                    isSubSeq = false;
                    break;
                }
                
                pos = *it;
            }            
            
            if(isSubSeq) {
                subSeqCount++;
            }
        }
        
        return subSeqCount;
    }
};