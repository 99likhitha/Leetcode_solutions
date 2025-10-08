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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || p==root || q==root) return root;

        TreeNode*leftLCA=NULL,*rightLCA=NULL;
        if( (p->val<root->val && q->val>root->val) || (p->val>root->val && q->val<root->val) ) return root;
        if(p->val<root->val && q->val<root->val)
        {
            leftLCA=lowestCommonAncestor(root->left,p,q);
        }

        if(p->val >root->val && q->val>root->val)
        {
            rightLCA=lowestCommonAncestor(root->right,p,q);
        }

        if(leftLCA && rightLCA) return root;

        return leftLCA?leftLCA :rightLCA;
    }
};