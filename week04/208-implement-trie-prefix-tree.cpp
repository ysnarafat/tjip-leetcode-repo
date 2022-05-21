// https://leetcode.com/problems/implement-trie-prefix-tree/

// Time Complexity - O(N)
// Memory Complexity - O(N) 

class TrieNode {
public:
    bool isWord;
    TrieNode* next[26];    
    
    TrieNode() {
        isWord = false;
        
        for(int i = 0; i < 26; i++) {
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
    
    void insert(string word) {
        TrieNode* currentNode = root;

        for(auto c : word) {
            int order = c - 'a';

            if(currentNode->next[order] == NULL) {
                currentNode->next[order] =  new TrieNode();
            }
            
            currentNode = currentNode->next[order];
        }
        
        currentNode->isWord = true;       
        
    }
    
    bool search(string word, bool isPrefixSearch = false) {
        TrieNode* currentNode = root;

        for(auto c : word) {
            int order = c - 'a';

            if(currentNode->next[order] == NULL) {
                return false;
            }
            
            currentNode = currentNode->next[order];
        }
        
        return (currentNode && (currentNode->isWord || isPrefixSearch));    
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */