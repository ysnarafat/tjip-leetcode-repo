/**

https://leetcode.com/problems/add-two-numbers/

Time Complexity - O(N)
Memory Complexity - O(1) [Only the returning LinkedList is used]

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
    void addNode(ListNode*& head) {
        head->next = new ListNode();
        head = head->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        auto head = sum;
        
        int rem = 0;

        while(l1 and l2) {
            sum->val = (l1->val + l2->val + rem) % 10;
            rem = (l1->val + l2->val + rem) / 10; 
            
            if(l2->next || l1->next) {
                addNode(sum);
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1) {
            sum->val = (l1->val + rem) % 10;
            rem = (l1->val + rem) / 10;

            if(l1->next) {
                addNode(sum);
            }            
            
            l1 = l1->next;        
        }
        
        while(l2) {
            sum->val =  (l2->val + rem) % 10;
            rem = (l2->val + rem) / 10;

            if(l2->next) {
                addNode(sum);
            }            
            
            l2 = l2->next;
        }
        
        if(rem) {
            addNode(sum);
            sum->val = rem;
        }
        
        return head;
    }
};