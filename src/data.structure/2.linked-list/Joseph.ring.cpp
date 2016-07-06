#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int _data=0):data(_data), next(NULL) {}
};

class Joseph {
private:
	Node *head;
public:
	Joseph() {
		// head: DO NOT STORE ANY DATA
		head = new Node;
		head->next = head;
	}
	~Joseph() {
		Node *current = head, *tmp = NULL;
		while (current->next != head) {
			tmp = current->next;
			current = tmp->next;
			delete tmp;
		}
		head = NULL;
	}

	bool insert(Node *node, int index) {
		int count = 0;
		Node *current = head;
		while (current->next != head) {
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
	bool remove(int index) {
		int count = 0;
		Node *current = head;
		while (current->next != head && count < index) {
			current = current->next;
			count++;
		}
		if (count == index && current->next != head) {
			Node *tmp = current->next;
			current->next = tmp->next;
			delete tmp;
			return true;
		}
		return false;
	}

	void josephus(int k) {
		Node *current = head, *tmp;
		while (current->next != current) {
			for (int i = 1; i < k; ++i) {
				current = current->next;
				if (current->next == head) {
					current = current->next;
				}
			}
			tmp = current->next;
			current->next = tmp->next;
			cout << tmp->data << " ";
			delete tmp;
		}
		return ;
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
};


int main()
{
	Joseph josephus;
	for (int i = 0; i < 10; ++i) {
		Node *node = new Node(i+1);
		josephus.insert(node, i);
	}
	josephus.print();
	josephus.josephus(3);

	return 0;
}