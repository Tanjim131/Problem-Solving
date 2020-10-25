
/* Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? 
In other words, performing n operations will take overall O(n) time even if one of those operations may take longer. */

// Push - O(1), Pop - O(1) Amortized ? 

// Push - O(n), Pop - O(1)
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack <int> s1, s2;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t = s1.top();
        s1.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */