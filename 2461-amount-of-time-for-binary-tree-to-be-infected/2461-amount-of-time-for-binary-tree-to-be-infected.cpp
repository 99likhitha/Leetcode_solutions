/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 void markparents(TreeNode*root, unordered_map<TreeNode*,TreeNode*>&parent_track,int start, TreeNode*&target)
    {
       
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*curr=q.front();
            q.pop();
            if(curr->val==start) target=curr;
            if(curr->left)
            {
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }

    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        TreeNode* target = nullptr;
        markparents(root,parent_track,start,target);

        if(!target) return 0;
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int dist=-1;
        while(!q.empty())
        {
          int size=q.size();
          dist++;
          for(int i=0;i<size;i++)
          {
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left]=true;
            }

            if(curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right]=true;
            }

            if(parent_track[curr] && !visited[parent_track[curr]])
            {
                q.push(parent_track[curr]);
                visited[parent_track[curr]]=true;
            }
          }
        }

        return dist;
        
    }
};