// https://leetcode.com/problems/valid-parentheses/

// Time Complexity - O(N)
// Memory Complexity - O(N)

class Solution {
public:
    bool isOpenParentheses(char ch) {
        if(ch == '(' or ch == '{' or ch == '[') {
            return true;
        }
        
        return false;
    }
    
    bool isValid(string s) {
        stack<char> st;
        int open = 0;
        int close = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(isOpenParentheses(s[i])) {
                open++;        
            }
            else {
                close++;
            }
        }
        
        if(open != close) {
            return false;
        }
        
        for(int i = 0; i < s.length(); i++) {           
            if(isOpenParentheses(s[i])) {
                st.push(s[i]);
            }
            else {
                if(!st.empty()) {
                    
                    if((s[i] == ')' and st.top() != '(') or 
                       (s[i] == '}' and st.top() != '{') or 
                       (s[i] == ']' and st.top() != '[')) {                        
                        return false;
                    }
                        
                    st.pop();
                }
            }
        }
        
        if(!st.empty()) {
            return false;
        }
        
        return true;
    }
};