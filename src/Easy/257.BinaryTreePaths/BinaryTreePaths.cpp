#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    vector<string> A;
public:
	void core_BTP(TreeNode* root, string t) {
		if (!root->left&&!root->right) {
			A.push_back(t);
			return;
		}
		if (root->left) core_BTP(root->left, t+"->"+to_string((root->left)->val));
		if (root->right) core_BTP(root->right, t+"->"+to_string((root->right)->val));
	}

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return NULL;
        core_BTP(root, to_string(root->val));
        return A;
    }
};


int main()
{
	cout<<to_string(5)<<endl;
	return 0;
}