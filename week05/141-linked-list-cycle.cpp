/**

https://leetcode.com/problems/linked-list-cycle/

Time Complexity - O(N)
Memory Complexity - O(N)

**/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        
        while(fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};