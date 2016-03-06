###打印出二叉树root到所有叶结点的路径  
	主要是用to_string这个函数 将一个int转成string  

	封装一个递归函数 `core_BTP(TreeNode* root, string t);` 其中root是递归的结点  
	string t 是从根结点到当前结点的路径表示字符串  

```cpp
void core_BTP(TreeNode* root, string t) {
	if (!root->left&&!root->right) { // 如果root到底了 说明这是最后一个结点了 所以收住这条路径、把这个t字符串push_back到A中
		A.push_back(t);
		return;
	}
	if (root->left) core_BTP(root->left, t+"->"+to_string((root->left)->val)); // 如果root有左子树，则递归左结点 并把左结点的值添加到string t后面
	if (root->right) core_BTP(root->right, t+"->"+to_string((root->right)->val)); // 如果root有右子树，则递归右结点 并把右结点的值添加到string t后面
}
```