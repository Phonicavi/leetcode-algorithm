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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalanced(root, height);
    }

    bool isBalanced(TreeNode* root, int& height) {
        if (!root) {
        	height = 0;
        	return true;
        }

        int hLeft, hRight;
        bool fLeft, fRight;
        fLeft = isBalanced(root->left, hLeft);
        fRight = isBalanced(root->right, hRight);

        height = 1 + max(hLeft, hRight);
        int diff = abs(hLeft - hRight);

        if (fLeft&&fRight&&diff <= 1) return true;
        else return false;
    }
};