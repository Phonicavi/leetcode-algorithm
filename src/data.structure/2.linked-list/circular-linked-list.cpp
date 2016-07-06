#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int _data=0):data(_data), next(NULL) {}
};

class CircList {
private:
	Node *head;
public:
	CircList() {
		// head: DO NOT STORE ANY DATA
		head = new Node;
		head->next = head;
	}
	~CircList() {
		Node *current = head, *need_remove = NULL;
		while (current->next != head) {
			need_remove = current;
			current = current->next;
			delete need_remove;
		}
		head = NULL;
	}
	bool insert(Node *node, int index) {
		if (!node) {
			return true;
		}
		int count = 0;
		Node *current = head;
		while (current->next != head && count < index) {
			current = current->next;
			count++;
		}
		if (count == index) {
			node->next = current->next;
			current->next = node;
			return true;
		}
		return false;
	}

	void print() const {
		Node *current = head;
		while (current->next != head) {
			current = current->next;
			cout << current->data << " ";
		}
		cout << endl;
		return ;
	}
	Node *getHead() const {
		return head;
	}
	
};

int main()
{
	CircList circlist;
	for (int i = 0; i < 10; ++i) {
		Node *node = new Node(i+1);
		circlist.insert(node, i);
	}

	circlist.print();
	Node *node = new Node(25);
	cout << circlist.insert(node, 11) << endl;
	circlist.print();

	// Node *h = circlist.getHead();
	// cout << h->next->next->data <<endl;

	return 0;
}