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

private:
    void getSum(TreeNode* node, int curNum, int&sum){
        if(!node){return;}
        curNum = curNum*2 + node->val;
        if(!node->left && !node->right){
            sum+=curNum;
            return;
        }
        getSum(node->left,curNum,sum);
        getSum(node->right,curNum,sum);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        getSum(root,0,sum);
        return sum;
    }
};