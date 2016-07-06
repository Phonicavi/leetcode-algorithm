#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int _data=0):data(_data), next(NULL) {}
};

class LinkList {
private:
	Node *head;
public:
	LinkList() {
		head = new Node;
	}
	~LinkList() {
		Node *current = head, *need_remove = NULL;
		while (current) {
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
		while (current->next && count < index) {
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
	Node *search(int value) const {
		Node *current = head->next;
		while (current) {
			if (value == current->data) {
				return current;
			}
			current = current->next;
		}
		return NULL;
	}
	bool remove(int index) {
		int count = 0;
		Node *current = head;
		while (current->next && count < index) {
			current = current->next;
			count++;
		}
		if (count == index && current->next) {
			Node *need_remove = current->next;
			current->next = need_remove->next;
			delete need_remove;
			return true;
		}
		return false;
	}
	void print() const {
		if (!(head->next)) {
			return ;
		}
		Node *current = head;
		while (current->next) {
			current = current->next;
			cout << current->data << " ";
		}
		cout << endl;
		return ;
	}
	void reverse() {
		// p->current->q
		Node *p = head->next;
		if (!p) return ;
		Node *current = p->next, *q;
		p->next = NULL;
		while (current) {
			q = current->next;
			current->next = p;
			p = current;
			current = q;
		}
		head->next = p;
		return ;
	}

	void recursive_reverse() {
		Node *new_h = core_recursive_reverse(head->next);
		head->next = new_h;
		return ;
	}
	Node *core_recursive_reverse(Node *h) {
		if (!(h->next)) return h;
		Node *new_r = h->next;
		Node *new_h = core_recursive_reverse(new_r);
		new_r->next = h;
		h->next = NULL;
		return new_h;
	}

	Node *getHead() const {
		return head;
	}
};

int main()
{
	LinkList linklist;

	for (int i = 0; i < 30; ++i) {
		Node *node = new Node(i);
		int v = i;
		if (!linklist.insert(node, v)) {
			break;
		}
	}
	linklist.print();

	cout << linklist.remove(2) << endl;
	linklist.print();
	
	Node *h = linklist.getHead();
	cout << h->next->next->next->data << endl;
	Node *sq = linklist.search(29);
	if (sq) {
		cout << "Found: " << sq->data << endl;
	} else {
		cout << "Not found" << endl;
	}

	linklist.reverse();
	linklist.print();

	linklist.recursive_reverse();
	linklist.print();

	return 0;
}