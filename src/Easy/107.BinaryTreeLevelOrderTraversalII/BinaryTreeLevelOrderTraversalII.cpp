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
    int level(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    
    void core_insert(vector<vector<int>>& ans, TreeNode* root, int level) {
        if (!root) return;
        ans[level].push_back(root->val);
        core_insert(ans, root->left, level-1);
        core_insert(ans, root->right, level-1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int L = level(root);
        vector<vector<int>> ans(L, vector<int>());
        core_insert(ans, root, L-1);
        return ans;
    }



    void coreInsertBottom(TreeNode* root, int height) {
        if (!root) return;
        if (A.size() == height) A.insert(A.begin(), vector<int>());
        A[A.size()-height-1].push_back(root->val);
        
        coreInsertBottom(root->left, height+1);
        coreInsertBottom(root->right, height+1);
    }

    vector<vector<int>> levelOrderBottom2(TreeNode* root) {
        coreInsertBottom(root, 0);
        return A;
    }
};