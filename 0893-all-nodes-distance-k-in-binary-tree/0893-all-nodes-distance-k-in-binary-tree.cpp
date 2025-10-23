/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode*root, unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode*target)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*curr=q.front();
            q.pop();
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        markparents(root,parent_track,target);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int dist=0;
        vector<int>answer;
        while(!q.empty())
        {
          int size=q.size();
          if(dist++ == k) break;
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

        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();
            answer.push_back(node->val);
        }
        return answer;
    }
};