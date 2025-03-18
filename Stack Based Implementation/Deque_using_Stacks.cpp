#include <iostream>
#include <stack>

using namespace std;

class Deque {
private:
    stack<int> frontStack, rearStack;

    void transfer(stack<int> &src, stack<int> &dest) {
        while (!src.empty()) {
            dest.push(src.top());
            src.pop();
        }
    }

public:
    void pushFront(int value) {
        frontStack.push(value);
    }

    void pushRear(int value) {
        rearStack.push(value);
    }

    void popFront() {
        if (frontStack.empty()) {
            if (rearStack.empty()) {
                cout << "Deque is empty\n";
                return;
            }
            transfer(rearStack, frontStack);
        }
        frontStack.pop();
    }

    void popRear() {
        if (rearStack.empty()) {
            if (frontStack.empty()) {
                cout << "Deque is empty\n";
                return;
            }
            transfer(frontStack, rearStack);
        }
        rearStack.pop();
    }

    int getFront() {
        if (frontStack.empty()) {
            if (rearStack.empty()) {
                cout << "Deque is empty\n";
                return -1;
            }
            transfer(rearStack, frontStack);
        }
        return frontStack.top();
    }

    int getRear() {
        if (rearStack.empty()) {
            if (frontStack.empty()) {
                cout << "Deque is empty\n";
                return -1;
            }
            transfer(frontStack, rearStack);
        }
        return rearStack.top();
    }

    bool isEmpty() {
        return frontStack.empty() && rearStack.empty();
    }
};

int main() {
    Deque dq;

    dq.pushFront(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.pushRear(25);

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    dq.popFront();
    cout << "Front after popFront: " << dq.getFront() << endl;

    dq.popRear();
    cout << "Rear after popRear: " << dq.getRear() << endl;

    return 0;
}
