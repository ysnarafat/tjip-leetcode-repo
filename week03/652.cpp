// https://leetcode.com/problems/find-duplicate-subtrees/

// Time Complexity - O(N) --> N = no of nodes
// Memory Complexity - O(N) 

class Solution {
public:
    unordered_map<string, int> subtreeCnt;
    vector<TreeNode*> duplicateSubTrees;
    
    string solve(TreeNode* root) {
        if(root == NULL) {
            return "#";
        }
        
        string leftStr = solve(root->left);
        string rightStr = solve(root->right);
        
        string strOfSubtree = "(" + leftStr + to_string(root->val) + rightStr + ")";
        
        subtreeCnt[strOfSubtree]++;
        
        if(subtreeCnt[strOfSubtree] == 2) {
            duplicateSubTrees.push_back(root);
        }
        
        return strOfSubtree;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        
        return duplicateSubTrees;
    }
};