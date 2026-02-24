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
    void getsum(TreeNode*node,int currNum, int &sum)
    {
        if(!node) return;
        currNum=currNum*2 + node->val;
        if(!node->left && !node->right)
        {
             sum+=currNum;
        }    
        getsum(node->left,currNum,sum);
        getsum(node->right,currNum,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        getsum(root,0,sum);
        return sum;
    }
};