#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	int id, height;
	Node(int _id=0, int _height=0):id(_id), height(_height) {}
};

template <class Type> class Stack {
private:
	int max_size, top_index;
	Type *data;
public:
	Stack(int length_input):max_size(length_input), top_index(-1) {
		data = new Type[max_size];
	}
	~Stack() {
		delete [] data;
	}

	bool push(const Type &_data) {
		if (full()) {
			return false;
		}
		data[++top_index] = _data;
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

int main()
{
	/* 
		地上从左到右竖立着 n 块木板，从 1 到 n 依次编号。
		我们知道每块木板的高度，在第 n 块木板右侧竖立着一块高度无限大的木板，
		现对每块木板依次做如下的操作：
		对于第 i 块木板，我们从其右侧开始倒水，直到水的高度等于第 i 块木板的高度，倒入的水会淹没 ai 块木板
		（如果木板左右两侧水的高度大于等于木板高度即视为木板被淹没），
		求分别对每一块木板如此操作，ai 是多少 
	*/
	/*
		即：有一个数组 求每个数到它右边第一个比他大的数之间有多少数
	*/
	int n;
	cin >> n;
	Stack<Node> stack(n);
	int *p = new int[n], current_height;
	for (int i = 0; i < n; ++i) {
		cin >> current_height;
		Node current(i, current_height);
		while (!stack.empty() && stack.top().height <= current.height) {
			p[stack.top().id] = current.id-stack.top().id-1;
			stack.pop();
		}
		stack.push(current);
	}
	while (!stack.empty()) {
		p[stack.top().id] = n-stack.top().id-1;
		stack.pop();
	}

	for (int i = 0; i < n; ++i) {
		cout << p[i] << " ";
	}
	cout << endl;

	return 0;
}