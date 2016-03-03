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
private:
    vector<vector<int>> A;
public:
    void coreInsert(TreeNode* root, int level) {
        if (!root) return;
        if (A.size() == level) A.push_back(vector<int>());
        A[level].push_back(root->val);
        
        coreInsert(root->left, level+1);
        coreInsert(root->right, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        coreInsert(root, 0);
        return A;
    }
};