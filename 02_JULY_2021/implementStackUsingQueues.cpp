#include <queue>
#include <deque>
#include <iostream>
using namespace std;

// Using queue
class MyStack {
private:
    queue<int> items;

public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> temp;
        temp.push(x);
        while (!items.empty()) {
            temp.push(items.front());
            items.pop();
        }
        items.swap(temp);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = this->top();
        items.pop();    
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return items.front(); 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
       return items.empty(); 
    }
};

// Using deque 
class MyStackDeque {
private:
    deque<int> items;

public:
    /** Initialize your data structure here. */
    MyStackDeque() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        items.push_back(x);        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = this->top();
        items.pop_back();    
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return items.back(); 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
       return items.empty(); 
    }
};

int main(void) {
    MyStack *myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    cout << myStack->top() << endl; // return 2
    cout << myStack->pop() << endl; // return 2
    cout << myStack->empty() << endl; // return False
    cout << myStack->top() << endl; // return 1
}