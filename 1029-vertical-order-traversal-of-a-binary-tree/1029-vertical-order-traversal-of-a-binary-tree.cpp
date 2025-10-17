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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<tuple<TreeNode*,int,int>>q;
        map<int,vector<pair<int,int>>>mp;

        if(root==NULL) return {};
        q.push({root,0,0});

        while(!q.empty())
        {
            auto [curr,col,row]=q.front();
            q.pop();
            mp[col].push_back({row,curr->val});


            if(curr->left) q.push({curr->left,col-1,row+1});
            if(curr->right) q.push({curr->right,col+1,row+1});
            
        }

        for(auto &itr:mp)
        {
            vector<pair<int,int>>v=itr.second;
            sort(v.begin(),v.end());
            vector<int>col_nodes;
            for(auto &it:v)
            {
                col_nodes.push_back(it.second);
            }

            ans.push_back(col_nodes);
        }
        return ans;
    }
};