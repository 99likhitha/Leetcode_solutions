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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1,-1};
        vector<int>criticals;
        ListNode*prev=head;
        ListNode*temp=head->next;
        int count=2;
        while(temp!=NULL && temp->next !=NULL)
        {
            if( (temp->val > prev->val && temp->val > temp->next->val) || (temp->val < prev->val && temp->val < temp->next->val) ) 
            {
               criticals.push_back(count); 
            }
            count++;
            prev=temp;
            temp=temp->next;
            
        }

        // for(int i:criticals)
        // {
        //     cout<<i<<endl;
        // }
        int n=criticals.size();
        if(n>=2)
        {
            int minima=INT_MAX;
            ans[1] = criticals[n-1] - criticals[0];
            for(int i=n-1;i>0;i--)
            {
                minima=min(minima, criticals[i]-criticals[i-1]);
            }
            ans[0]=minima;
        }
    



        return ans;

    }
};