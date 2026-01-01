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
    void deleteNode(ListNode* node) {
        ListNode*prev=NULL;
        // ListNode*curr=NULL;
        ListNode*curr=node->next;
        curr->val=node->next->val;
        node->val=curr->val;
        node->next=curr->next;

        delete(curr);

        
    }
};