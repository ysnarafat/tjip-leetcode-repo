/**

https://leetcode.com/problems/reverse-linked-list/

Time Complexity - O(N)
Memory Complexity - O(1)

**/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prev = NULL) {
        if(!head) return prev;
        
        auto next = head->next;
        head->next = prev;
        
        return reverseList(next, head);
    }
};