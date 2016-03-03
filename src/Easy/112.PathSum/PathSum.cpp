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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (root->val == sum&&!root->left&&!root->right) return true;
//        else if (root->val > sum) return false; // sum不一定是正数 不应该判断大小😂
        else return hasPathSum(root->left, sum-(root->val))||hasPathSum(root->right, sum-(root->val));
    }
};