#include <iostream>
#include <stack>

using namespace std;

class MaxStack {
private:
    stack<int> s, maxS;

public:
    void push(int val) {
        s.push(val);
        if (maxS.empty() || val >= maxS.top()) maxS.push(val);
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == maxS.top()) maxS.pop();
        s.pop();
    }

    int top() {
        if (s.empty()) return -1;
        return s.top();
    }

    int getMax() {
        if (maxS.empty()) return -1;
        return maxS.top();
    }

    bool isEmpty() {
        return s.empty();
    }
};

int main() {
    MaxStack maxStack;
    maxStack.push(5);
    maxStack.push(10);
    maxStack.push(3);
    maxStack.push(12);

    cout << "Max: " << maxStack.getMax() << endl;
    maxStack.pop();
    cout << "Max after pop: " << maxStack.getMax() << endl;
    cout << "Top: " << maxStack.top() << endl;

    return 0;
}
