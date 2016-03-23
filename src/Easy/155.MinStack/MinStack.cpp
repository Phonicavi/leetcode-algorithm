class MinStack {
private:
    stack<int> Vec;
    stack<int> Min;
public:
    void push(int x) {
        Vec.push(x);
        if (Min.empty()||x <= Min.top()) Min.push(x);
    }

    void pop() {
        if (Vec.empty()||Min.empty()) return;
        int mini = Min.top();
        if (mini == Vec.top()) Min.pop();
        Vec.pop();
    }

    int top() {
        return Vec.top();
    }

    int getMin() {
        return Min.top();
    }
};