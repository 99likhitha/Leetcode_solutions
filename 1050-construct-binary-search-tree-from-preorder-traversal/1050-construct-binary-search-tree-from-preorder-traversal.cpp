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
TreeNode*build(vector<int>&preorder,int prestart,int preend)
{
    if(prestart>preend) return NULL;
    TreeNode*root=new TreeNode(preorder[prestart]);
    int nums=preend;
    for(int i=prestart+1;i<=preend;i++)
    {
        if(preorder[i]>preorder[prestart]) 
        {
            nums=i-1;
            break;
        }
    }
    root->left=build(preorder,prestart+1,nums);
    root->right=build(preorder,nums+1,preend);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
       int n=preorder.size();
       return build(preorder,0,n-1);

    }
};