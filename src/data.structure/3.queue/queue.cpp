#include <iostream>
#include <cassert>
using namespace std;

// FIFO: First In First Out
class Queue {
private:
	int *data;
	int length, head, tail;
public:
	Queue(int length_input=0):length(length_input), head(0), tail(-1) {
		data = new int[length];
	}
	~Queue() {
		delete [] data;
	}

	bool push(int value) {
		if (tail+1 < length) {
			tail++;
			data[tail] = value;
			return true;
		}
		return false;
	}
	bool pop() {
		if (head <= tail) {
			head++;
			return true;
		}
		return false;
	}

	void print() const {
		for (int i = head; i <= tail; ++i) {
			cout << data[i] << " ";
		}
		cout << endl;
		return ;
	}
	int top() const {
		assert(head <= tail);
		return data[head];
	}
	bool empty() const {
		return (head > tail);
	}
	int getLength() const {
		return length;
	}
};
int main()
{
	Queue queue(10);

	cout << queue.empty() << endl;
	queue.push(-1);
	cout << queue.empty() << endl;
	queue.push(0);
	
	for (int i = 1; i <= 10; ++i) {
		queue.push(i);
	}
	cout << queue.empty() << endl;
	queue.print();

	cout << queue.top() << endl;

	queue.pop();
	queue.print();

	return 0;
}