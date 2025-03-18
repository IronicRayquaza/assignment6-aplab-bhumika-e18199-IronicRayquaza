#include <iostream>
#include <stack>

using namespace std;

class PriorityQueue {
private:
    stack<int> s1, s2;

    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void push(int val) {
        while (!s1.empty() && s1.top() > val) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if (!s1.empty()) s1.pop();
    }

    int top() {
        if (s1.empty()) return -1;
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    cout << "Top: " << pq.top() << endl;
    pq.pop();
    cout << "Top after pop: " << pq.top() << endl;

    return 0;
}
