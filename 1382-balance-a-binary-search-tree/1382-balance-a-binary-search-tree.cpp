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
    vector<int>inord;
   void Inorder(TreeNode*root)
    {
        if(root==NULL) return ;
        Inorder(root->left);
        inord.push_back(root->val);
        Inorder(root->right);
        
    }

    TreeNode*ConstructBSTInorder(vector<int>&intraversal,int low,int high)
    {

        if(low>high) return NULL;
        int n=intraversal.size();
        int mid = low + (high-low)/2;
        TreeNode*root=new TreeNode(intraversal[mid]);
        root->left=ConstructBSTInorder(intraversal,low,mid-1);
        root->right=ConstructBSTInorder(intraversal,mid+1,high);

        return root;

    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return NULL;
        Inorder(root);
        int n=inord.size();
        return ConstructBSTInorder(inord,0,n-1);

    }
};