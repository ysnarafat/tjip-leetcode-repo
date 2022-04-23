// https://leetcode.com/problems/implement-strstr/

// Time Complexity - O(N)
// Memory Complexity - O(N)
class Solution {
public:
    vector<int> kmpPreprocess(string pattern) {
        int i = 1, j = 0;
        vector<int> result(pattern.length());
        
        while(i < pattern.length()) {
            if(pattern[i] == pattern[j]) {
                result[i] = j + 1;
                i++; 
                j++;
            } 
            else if (j > 0) {
                j = result[j - 1];
            } 
            else {
                result[i] = 0;
                i++;
            }
        }
        
        return result;
    }
    
    int strStr(string haystack, string needle) {
        int ans = -1;
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        
        if(needleLen > haystackLen) {
            return ans;
        }
        
        vector<int> pre = kmpPreprocess(needle);
        int i = 0, j = 0;
        
        while(i < haystackLen and j < needleLen) {
            if(haystack[i] == needle[j]) {
                i++; 
                j++;
            } 
            else if(j > 0) {
                j = pre[j - 1];
            } 
            else {
                i++;
            }
        }
        
        ans = i - j;
        
        return j == needle.length() ? ans : -1;
    }
};