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
    bool fillup(TreeNode* root,TreeNode* node,vector<TreeNode*>&parent){
        if(root==NULL)return false;
        parent.push_back(root);
        if(root==node)return true;
        if(fillup(root->left,node,parent)||fillup(root->right,node,parent)){
            return true;
        }
        parent.pop_back();
        return false;

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        vector<TreeNode*>Pa,Pb;

        if(fillup(root,a,Pa)&&fillup(root,b,Pb)){
            int n=Pa.size();
            int m=Pb.size();
            int i=0;
            int j=0;
            while(i<n&&j<m){
                if(Pa[i]!=Pb[j])return Pa[i-1];
                i++;
                j++;
            }
            if(i<n)return Pa[i-1];
            else if(j<m)return Pb[j-1];
        }

        return NULL;

    }
};