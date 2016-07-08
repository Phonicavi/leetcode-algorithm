#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
    int max_size, top_index;
    int *data;
public:
    Stack(int length_input):max_size(length_input), top_index(-1) {
        data = new int[max_size];
    }
    ~Stack() {
        delete [] data;
    }
    bool push(const int &value) {
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
    int top() const {
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

int main() {
    int N;
    cin >> N;
    Stack stack(N);
    int *p = new int[N];
    // input: N
    // input: N numbers within 1 ~ N
    // 判断1到N的某个排列是否是合法的出栈顺序
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }
    int j = 0;
    for (int i = 1; i <= N && j < N; ) {
        if (stack.empty() || p[j] != stack.top()) {
            stack.push(i);
            i++;
        } else {
            stack.pop();
            j++;
        }
    }
    while (!stack.empty() && j < N) {
        if (p[j] == stack.top()) {
            j++;
            stack.pop();
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}