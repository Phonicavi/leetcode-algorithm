#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    int maxDepth(TreeNode* root) {
        if (!root) {
        	return 0;
        } else if (root->left&&!root->right) {
        	return maxDepth(root->left) + 1;
        } else if (!root->left&&root->right) {
        	return maxDepth(root->right) + 1;
        } else {
        	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    }
    // which can be written in one line
    int maxDepth0(TreeNode *root) {
    	return root == NULL ? 0 : (max(maxDepth0(root->left), maxDepth0(root->right))+1) ;
    }

    int maxDepth2(TreeNode *root) {
        if (!root) return 0;

        queue<TreeNode *> q;
        int height = 0;
        q.push(root);
        while (!q.empty()) {
        	++height;
        	// 注意不能写成q.size() 因为循环内要对q做弹出弹入操作 这样q.size()会变动
        	// for (int i=0; i<q.size(); ++i) {
        	for (int i=0, n = q.size(); i<n; ++i) {
        		TreeNode *hd = q.front();
        		q.pop();
        		if (hd->left) q.push(hd->left);
        		if (hd->right) q.push(hd->right);
        	}
        }
        return height;
    } 
};