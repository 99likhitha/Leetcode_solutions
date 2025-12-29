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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return {};
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            TreeNode*node=p.first;
            int d=p.second;
            mp[d].push_back(node->val);

            if(node->left)
            {
                q.push({node->left,d-1});
            }
            if(node->right)
            {
                q.push({node->right,d+1});
            }
        }


        for(auto &itr:mp)
        {
            ans.push_back(itr.second);
        }
        return ans;
    }
};