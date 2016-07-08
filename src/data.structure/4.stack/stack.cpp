#include <iostream>
#include <cassert>
using namespace std;

template <class Type> class Stack {
private:
	Type *data;
	int max_size, top_index;
public:
	Stack(int length_input):max_size(length_input), top_index(-1) {
		data = new Type[max_size];
	}
	~Stack() {
		delete [] data;
	}

	bool push(const Type &element) {
		if (full()) {
			return false;
		}
		data[++top_index] = element;
		return true;
	}
	Type top() const {
		assert(!empty());
		return data[top_index];
	}
	bool pop() {
		if (empty()) {
			return false;
		}
		top_index--;
		return true;
	}

	bool empty() const {
		return (top_index < 0);
	}
	bool full() const {
		return (top_index >= max_size-1);
	}
};

int main()
{
	Stack<int> stack(10);

	for (int i = 0; i < 20; ++i) {
		if (stack.push(i)) {
			cout << "push success: " << i << endl;
		}
	}

	while (!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
	
	return 0;
}