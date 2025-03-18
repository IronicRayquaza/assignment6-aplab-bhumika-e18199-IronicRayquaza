#include <iostream>
#include <queue>

using namespace std;

class Deque {
private:
    queue<int> q1, q2;

public:
    void pushFront(int val) {
        q2.push(val);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pushRear(int val) {
        q1.push(val);
    }

    void popFront() {
        if (q1.empty()) {
            cout << "Deque is empty\n";
            return;
        }
        q1.pop();
    }

    void popRear() {
        if (q1.empty()) {
            cout << "Deque is empty\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }

    int getFront() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    int getRear() {
        if (q1.empty()) return -1;
        int rear;
        while (!q1.empty()) {
            rear = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        return rear;
    }

    bool isEmpty() {
        return q1.empty();
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
