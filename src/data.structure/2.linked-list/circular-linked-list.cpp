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
	Node *search(int value) const {
		Node *current = head;
		while (current->next != head) {
			current = current->next;
			if (value == current->data) {
				return current;
			}
		}
		return NULL;
	}
	bool remove(int index) {
		int count = 0;
		Node *current = head;
		while (current->next != head && count < index) {
			current = current->next;
			count++;
		}
		if (count == index && current->next != head) {
			Node *need_remove = current->next;
			current->next = need_remove->next;
			delete need_remove;
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

	cout << circlist.remove(2) << endl;
	circlist.print();

	cout << circlist.remove(4) << endl;
	circlist.print();

	Node *sq = circlist.search(6);
	if (sq) {
		cout << "Found: " << sq->data << endl;
	} else {
		cout << "Not found" << endl;
	}

	return 0;
}