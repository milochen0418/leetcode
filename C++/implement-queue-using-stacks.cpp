class MyQueue {
    //https://leetcode.com/problems/implement-queue-using-stacks
    //article https://leetcode.com/problems/implement-queue-using-stacks/discuss/2349190/C%2B%2B-or-using-temporary-stack-only-in-pop()
public:
    stack<int> stk;
    int front;//front of q
    MyQueue() {
        
    }
    
    void push(int x) {
        if(stk.empty()) front = x;
        stk.push(x);
    }
    
    int pop() {
        stack<int> tmp; 
        while(!stk.empty()) {
            tmp.push(stk.top());
            stk.pop();
        }
        
        int ret = tmp.top();
        tmp.pop();
        front = tmp.empty()?INT_MIN:tmp.top();
        
        while(!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        } 
        return ret;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return stk.empty();
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