#include <stack>
#include <iostream>
using namespace std;

// Method 1 -> TC = O(1) SC = O(N)
class MinStack {
private:
    // store actual value
    stack<int> s1;
    // store min value
    stack<int> s2;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int val) {
        s1.push(val);
        
        if (s2.empty()) s2.push(val);
        else s2.push(min(val, s2.top()));
    }
    
    void pop() {
       s1.pop();
       s2.pop(); 
    }
    
    int top() {
        return s1.top(); 
    }
    
    int getMin() {
        return s2.top(); 
    }
};

int main(void) {
   MinStack *obj = new MinStack();
   obj->push(3);
   obj->push(2);
   obj->push(10);
   cout << "min: " << obj->getMin() << endl; // 2
   obj->push(1);
   cout << "min: " << obj->getMin() << endl; // 1
   obj->pop();
   obj->pop();
   cout << "top: " << obj->top() << endl; // 2
}
