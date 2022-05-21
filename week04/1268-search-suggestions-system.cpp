// https://leetcode.com/problems/search-suggestions-system/

// Time Complexity - O(len(str) + 26* (N + E)) --> O(len(str) + (N + E))
// Memory Complexity - O(N) 

class TrieNode {
public:
    int isWord;
    TrieNode* next[26];
    
    TrieNode() {
        isWord = false;
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
    
    // O(len(str) + 26* (N + E)) 
    vector<string> search(string pre) {        
        vector<string> ans;
        TrieNode* currentNode = root;
        
        for(auto c : pre) {
            int ch = c - 'a';
            
            if(currentNode->next[ch] == NULL) {
                return {};
            }
            
            currentNode = currentNode->next[ch];
        }
        
        dfs(currentNode, pre, ans);
        return ans;
    }
    
    // O(26* (N + E))
    void dfs(TrieNode* currentNode, string pre, vector<string> &ans) {         
        if(ans.size() == 3) {
            return ;
        }
         
         if(currentNode->isWord) {
            ans.push_back(pre);
        }            
        
        for(int i=0; i<26; i++) {
            if(currentNode->next[i]) {
                dfs(currentNode->next[i], pre + ((char) (i + 'a')), ans);                 
            }
        }
    }
    
    // O(len(str))
    void insertString(string str) {
        TrieNode* currentNode = root;
        
        for(auto c : str) {
            int ch = c - 'a';
            
            if(currentNode->next[ch] == NULL) {
                currentNode->next[ch] = new TrieNode();
            }
            
            currentNode = currentNode->next[ch];       
        }
        
        currentNode->isWord = true;                 
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        Trie* obj = new Trie();
        
        for(auto product : products) {
            obj->insertString(product);
        }
        
        string pre="";
        for(auto c : searchWord) {
            pre += c;
            res.push_back(obj->search(pre));
        }
        
        return res;
    }
};