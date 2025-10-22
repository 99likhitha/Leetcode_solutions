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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        using ULL = unsigned long long;      
        queue<pair<TreeNode*,ULL>>q;
        map<int, pair<ULL,ULL>>mp;
        if(root==NULL) return 0;
        q.push({root,1});
        mp[0]={1,1};
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            ULL base=q.front().second;
            for(int i=0;i<size;i++)
            {
                auto [node,pos]=q.front();
                q.pop();
                ULL idx=pos-base;           
                if(i==0) mp[level]={idx,idx};
                else{
                mp[level].first=min(mp[level].first,idx);
                mp[level].second=max(mp[level].second,idx);
                }
                if(node->left) q.push({node->left, idx*2});
                if(node->right) q.push({node->right,idx*2+1});
            }
            level++;
        }

        int maxwidth=0;
        for(auto &[level,range]:mp)
        {
            maxwidth=max(maxwidth,(int)(range.second-range.first+1));
        }

        return maxwidth;

    }
};