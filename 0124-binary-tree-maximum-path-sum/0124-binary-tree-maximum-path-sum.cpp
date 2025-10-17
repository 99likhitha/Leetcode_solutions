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
    int pathsum(TreeNode*root,int &maxsum){
    if(root==NULL) return 0;
    int leftsum=max(0,pathsum(root->left,maxsum));
    int rightsum=max(0,pathsum(root->right,maxsum));

    maxsum=max(maxsum,leftsum+rightsum+root->val);
    return root->val + max(leftsum,rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        pathsum(root,ans);
        return ans;
    }
};