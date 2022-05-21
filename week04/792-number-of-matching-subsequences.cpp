// https://leetcode.com/problems/number-of-matching-subsequences/

// Time Complexity - O(26 * len(s) * (N + E)) --> O(len(s) * (N + E))
// Memory Complexity - O(N) 

class TrieNode {
public:
    TrieNode* next[26];
    bool isWord;
    int count; 
    
    TrieNode() { 
        isWord = false; 
        count = 0;
        
        for(int i = 0 ; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { 
        root = new TrieNode(); 
    }
    
    // O(len(s))
    void insert(string s) {
        TrieNode* currentNode = root;
        for(char c : s) {
            int ch = c - 'a';
            if(currentNode->next[ch] == NULL)
                currentNode->next[ch] = new TrieNode();
            
            currentNode = currentNode->next[ch];
        }
        
        currentNode->isWord = true;
        currentNode->count++; 
    }
   
};

class Solution {    
public:
    int ans = 0;
    
    // O(len(s))
    int findIndex(const string &s, int start, char c) {
        for(int i = start; i < s.size(); i++) {
            if(s[i] == c) {
                return i;
            }
        }            
        
        return -1;
    }
    
    // O(26 * len(s) * (N + E))
    void dfs(const string& s, TrieNode* node, int start) {
        for(int i = 0; i < 26; i++) {
            if(node->next[i] == NULL) continue;
            
            int idx = findIndex(s, start, (char) (i + 'a'));
            
            if(idx != -1) {
                auto currentNode = node->next[i];
            
                if(currentNode->isWord == true) {
                    ans += currentNode->count;
                }
                
                dfs(s, currentNode, idx + 1);
            }                
        }
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        Trie* trie = new Trie();

        for(string word : words) {
            trie->insert(word);
        }
            
        dfs(s, trie->root, 0);
        
        return ans;
    }
};