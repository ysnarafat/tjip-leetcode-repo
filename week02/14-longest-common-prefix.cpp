// https://leetcode.com/problems/longest-common-prefix/

// Time Complexity - O(N * M) --> N = size of the string array, M = size of each string 
// Memory Complexity - O(N) --> N = size of resultant string

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string currLongestPrefix = strs[0], newLongestPrefix = "";
        int j = 0, k = 0, len = currLongestPrefix.length();
        
        for(int i = 1; i < strs.size(); i++) {            
            string currentString = strs[i];
            int currentStringLen = strs[i].length();
            
            while(k < currentStringLen && j < len) {                
                if(currentString[k] != currLongestPrefix[j]) {    
                    break;
                }
                
                newLongestPrefix += currentString[k];
                j++;
                k++;
            }
            
            currLongestPrefix = newLongestPrefix;
            newLongestPrefix = "";
            j = 0;
        }        
        
        return currLongestPrefix;
    }
};