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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> Queue;

        Queue.push(root->left);
        Queue.push(root->right);
        while (!Queue.empty()) {
            auto p = Queue.front();
            Queue.pop();
            auto q = Queue.front();
            Queue.pop();
            if ((!p&&q)||(p&&!q)) return false;
            if (p&&q) {
                if (p->val != q->val) return false;
                
                Queue.push(p->left);
                Queue.push(q->right);
                Queue.push(p->right);
                Queue.push(q->left);
            }
            // 出现(p == NULL&&q == NULL)的情况 什么都不做 继续下一次循环，调出后面的结点对
        }
        
        return true;
    }

    bool isSymmetric2(TreeNode* root) {
        if (!root) return true;
        return isTwoSymmetric(root->left, root->right);
    }

    bool isTwoSymmetric(TreeNode* p, TreeNode* q) {
    	if (!p&&!q) return true;
    	else if (!p||!q) return false;
    	else {
    		if (p->val != q->val) return false;

    		return isTwoSymmetric(p->left, q->right)&&isTwoSymmetric(p->right, q->left);
    	}
    }
};