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
    ListNode* Reverselist(ListNode*head)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*temp=NULL;
        while(curr!=NULL)
        {
           temp=curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp;   
        }


        return prev;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer=NULL;
        ListNode* tail=NULL;
        int carry=0;
        while(l1 !=NULL || l2!=NULL || carry>0)
        {
            int num1=(l1!=NULL)?l1->val:0;
            int num2=(l2!=NULL)?l2->val:0;
            int sum=num1+num2+carry;
            ListNode*temp=new ListNode(sum%10);
            carry=sum/10;
            if(answer == NULL)
            {
                answer=temp;
                tail=temp;
            }
            else
            {
                tail->next=temp;
                tail=temp;
            }
            
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }

        return answer;
    }
};