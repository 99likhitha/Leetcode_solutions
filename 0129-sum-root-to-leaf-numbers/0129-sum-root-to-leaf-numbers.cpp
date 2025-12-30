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
int sum=0;
    void roottoleaf(TreeNode*root,string s)
    {
        if(root==NULL) return;

        s+=char(root->val +'0');

        if(!root->left && !root->right)
        {
            sum+=stoi(s);
            return;
        }

       roottoleaf(root->left,s);
       roottoleaf(root->right,s);

    }
    int sumNumbers(TreeNode* root) {
        if(!root) return NULL;
        string s="";
        roottoleaf(root,s);
        return sum;

    }
};