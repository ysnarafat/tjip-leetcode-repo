// https://leetcode.com/problems/ugly-number-ii/

// Time Complexity - O(N)
// Memory Complexity - O(N) 

class Solution {
public:    
    int nthUglyNumber(int n) {
        vector<long> uglyNumbers;
        uglyNumbers.push_back(1);
        
        int i = 0, j = 0, k = 0;
        
        for(int l = 2; l <= n; l++) {
            long currentUglyNumber = min(uglyNumbers[i] * 2, min(uglyNumbers[j] * 3, uglyNumbers[k] * 5));
            
            if(currentUglyNumber == uglyNumbers[i] * 2) {
                i++;
            }
            if(currentUglyNumber == uglyNumbers[j] * 3) {
                j++;
            }
            if(currentUglyNumber == uglyNumbers[k] * 5) {
                k++;
            }
            
            uglyNumbers.push_back(currentUglyNumber);
        }
        
        return uglyNumbers[n-1];
    }
};