#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *lchild, *rchild;
public:
	Node(int _data):data(_data), lchild(NULL), rchild(NULL){};
	~Node(){};
};

class BinaryTree {
private:
	Node *root;
public:
	BinaryTree():root(NULL){};
	~BinaryTree(){};
};

int main()
{
	BinaryTree binarytree;
	return 0;
}