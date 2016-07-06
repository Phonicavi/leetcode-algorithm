#include <iostream>
#include <cassert>
using namespace std;

class Queue {
private:
	int *data;
	int length, head, tail, count;
public:
	Queue(int length_input=0):length(length_input), head(0), tail(-1), count(0) {
		data = new int[length];
	}
	~Queue() {
		delete [] data;
	}
	
	bool push(int value) {
		if (count < length) {
			tail = (tail+1)%length;
			data[tail] = value;
			count++;
			return true;
		}
		return false;
	}
	bool pop() {
		if (count > 0) {
			head = (head+1)%length;
			count--;
			return true;
		}
		return false;
	}

	void print() const {
		for (int i = head; i < length; ++i) {
			cout << data[i] << " ";
		}
		for (int i = 0; i <= tail; ++i) {
			cout << data[i] << " ";
		}
		cout << endl;
		return ;
	}
	int top() const {
		assert(count > 0);
		return data[head];
	}
	bool empty() const {
		return (count == 0);
	}

	int getLength() const {
		return length;
	}
	int getCount() const {
		return count;
	}
	int getHead() const {
		return head;
	}
	int getTail() const {
		return tail;
	}
};
int main()
{
	Queue queue(5);
    for (int i = 1; i <= 10; i++) {
    	cout << "num: " << queue.getCount() << " ";
        cout << "success? " << queue.push(i) << endl;
    }
    // cout << queue.getCount() << endl;
    // cout << queue.getHead() << " " << queue.getTail() << endl;
    queue.print();
    cout << queue.top() << endl;
    queue.pop();
    queue.print();

    queue.pop();
    queue.pop();
    queue.print();
    cout << queue.getHead() << " " << queue.getTail() << endl;
    
    cout << queue.push(8) << endl;
    queue.print();
    
    cout << queue.push(12) << endl;
    queue.print();
    
    cout << queue.push(16) << endl;
    cout << queue.getHead() << " " << queue.getTail() << endl;
    queue.print();

    cout << queue.push(20) << endl;
    queue.print();

	return 0;
}