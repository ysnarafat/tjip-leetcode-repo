/**

https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

Time Complexity - O(N)
Memory Complexity - O(N)

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
    
    int pairSum(ListNode* head) {
        auto slow = head;
        auto fast = head;
        
        while(fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        ListNode* prev = NULL;
        auto current = slow->next;
           
        ListNode* res = reverseList(current, prev);
        
        long long sum = -1;
        
        while(head and res) {
            
            if(res == NULL) {
                sum =  max(sum, (long long)(head->val + head->val));
                break;
            }
            
            sum = max(sum, (long long)(head->val + res->val));
            head = head->next;
            res = res->next;
        }
        
        return sum;
    }
};