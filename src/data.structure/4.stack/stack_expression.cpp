#include <iostream>
#include <cassert>
#include <cstring>
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

	bool push(const Type &value) {
		if (full()) {
			return false;
		}
		data[++top_index] = value;
		return true;
	}
	bool pop() {
		if (empty()) {
			return false;
		}
		top_index--;
		return true;
	}
	Type top() const {
		assert(!empty());
		return data[top_index];
	}
	bool empty() const {
		return (top_index < 0);
	}
	bool full() const {
		return (top_index >= max_size-1);
	}
};

bool precede(char a, char b) {
	return (a == '*');
}
int operate(char opr, int a, int b) {
	switch (opr) {
	case '+':
		return a + b;
	case '*':
		return a * b;
	default:
		return 0;
	}
}
void calculate(Stack<int> &numbers, Stack<char> &operators) {
	int a = numbers.top();
	numbers.pop();
	int b = numbers.top();
	numbers.pop();
	numbers.push(operate(operators.top(), a, b));
	operators.pop();
	return ;
}

int main()
{
	int N;
	cin >> N;
	Stack<int> numbers(N);
	Stack<char> operators(N);

// here numbers in 0 ~ 9
// only +, *
	string buffer;
	cin >> buffer;
	int i = 0;
	while (i < N) {
		char x = buffer[i];
		if (isdigit(x)) {
			numbers.push(x-'0');
			++i;
		} else {
			if (operators.empty() || precede(x, operators.top())) {
				operators.push(x);
				++i;
			} else {
				calculate(numbers, operators);
			}
		}
		// if (!numbers.empty()) cout << numbers.top() << endl;
	}
	while (!operators.empty()) {
		calculate(numbers, operators);
	}
	cout << numbers.top() << endl;

	return 0;
}