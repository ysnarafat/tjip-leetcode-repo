// https://leetcode.com/problems/decode-string/

// Time Complexity - O(N)
// Memory Complexity - O(N)

class Solution {
public:
    static bool isNumber(char ch) {
        return (ch >= '0' && ch <= '9');
    }
    
    static string generateSeq(int num, string s) {
        string res;
        
        for(int i = 0; i < num; i++) {
            res += s;
        }
        
        return res;
    }
    
    string decodeString(string s) {
        stack<char> st;
        string ans, now, num;
        int i = 0, timesToRepeat = 0;
        
        while(i < s.length()) {
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else {
                while(!st.empty()) {
                    if(st.top() == '[') {
                        st.pop();
                        break;
                    }
                    
                    now = st.top() + now;
                    st.pop();
                }
                
                num = "";
                
                while(!st.empty() && isNumber(st.top())) {                    
                    num = st.top() + num;
                    st.pop();                   
                }
                
                timesToRepeat = stoi(num);                                
                now = generateSeq(timesToRepeat, now);
                
                for(auto ch : now) {
                    st.push(ch);
                }
            }
            
            i++;
            now = "";
        }
        
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
             
        return ans;
    }
};