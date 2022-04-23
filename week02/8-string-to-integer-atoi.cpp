// https://leetcode.com/problems/string-to-integer-atoi/

// Time Complexity - O(N)
// Memory Complexity - O(1)

class Solution {
public:
    int myAtoi(string s) {
        long long value = 0;
        int sign = 1, i = 0; 
        
        while(s[i] == ' ') {
            i++;
        }
        
        if (s[i] == '+' or s[i] == '-') {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }        
        
        while (i < s.length() and isdigit(s[i])) {
            value = value * 10 + (s[i] - '0');
            
            if (value * sign > INT_MAX) {
                return INT_MAX;
            }
            else if (value * sign < INT_MIN) {
                return INT_MIN;
            }            
            
            i++;
        }
        
        return value * sign;
    }
};