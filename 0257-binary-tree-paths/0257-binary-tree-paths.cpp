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
void dfs(TreeNode*node , vector<string>&ans, string path)
{
    if(node==NULL) return;

    if(!path.empty()) path+="->";
    path+=to_string(node->val);

    if(!node->left && !node->right)
    {
        ans.push_back(path);
        path="";
    }

    dfs(node->left,ans,path);
    dfs(node->right,ans,path);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path="";
        dfs(root,ans,path);
        return ans;
    }
};