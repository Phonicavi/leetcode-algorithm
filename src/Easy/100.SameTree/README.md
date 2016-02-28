###递归  
	深搜检查  
		- 同NULL判相等  
		- 一空一非空判不等  
		- 两个都不空 返回 (当前两根val相等)且(递归左子树相等)且(递归右子树相等)  

```cpp
// 一行代码
return (!p||!q) ? (p == q) : (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
```