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
    int height(TreeNode*root)
    {
        if(root==NULL) return 0;
        if(root && !root->left && !root->right) return 1;

        return 1+max(height(root->left),height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lh=0,rh=0;
        if(root && !root->left && !root->right) return true;
        if(root->left)
        {
            lh=height(root->left);
        }
        if(root->right)
        {
            rh=height(root->right);
        }
        int diff=abs(lh-rh);
        if(diff>1) return false;

        return isBalanced(root->left) && isBalanced(root->right);

    }
};