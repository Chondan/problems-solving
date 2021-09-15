#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> items;
    stack<int> temp;

public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        // Like moving items between two 2 buckets
        if (items.empty()) {
            items.push(x);
            return;
        }

        while (!items.empty()) {
            temp.push(this->pop());
        }
        items.push(x);

        while (!temp.empty()) {
            items.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = this->peek(); 
        items.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return items.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return items.empty();
    }
};

int main(void) {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    cout << obj->pop() << endl; // 1
    obj->push(5);
    cout << obj->pop() << endl; // 2
    cout << obj->pop() << endl; // 3
    cout << obj->pop() << endl; // 4
    cout << obj->pop() << endl; // 5
    cout << "isEmpty: " << obj->empty() << endl; // true
}
