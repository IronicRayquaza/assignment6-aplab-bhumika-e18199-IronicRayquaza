#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s, minS;

public:
    void push(int val) {
        s.push(val);
        if (minS.empty() || val <= minS.top()) minS.push(val);
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == minS.top()) minS.pop();
        s.pop();
    }

    int top() {
        if (s.empty()) return -1;
        return s.top();
    }

    int getMin() {
        if (minS.empty()) return -1;
        return minS.top();
    }

    bool isEmpty() {
        return s.empty();
    }
};

int main() {
    MinStack minStack;
    minStack.push(5);
    minStack.push(2);
    minStack.push(8);
    minStack.push(1);
    
    cout << "Min: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Min after pop: " << minStack.getMin() << endl;
    cout << "Top: " << minStack.top() << endl;

    return 0;
}
