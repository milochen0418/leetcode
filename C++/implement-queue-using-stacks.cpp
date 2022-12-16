

class MyQueue {
    //https://leetcode.com/problems/implement-queue-using-stacks
    //article O(N) pop -> https://leetcode.com/problems/implement-queue-using-stacks/discuss/2349190/C%2B%2B-or-using-temporary-stack-only-in-pop()
    //article O(N) push -> https://leetcode.com/problems/implement-queue-using-stacks/discuss/2916577/C%2B%2B-or-using-temporary-stack-only-in-push()
public:
    stack<int> stk;
    MyQueue() {}
    
    void push(int x) {
        stack<int> s2; 
        while(!stk.empty()) {
            s2.push(stk.top());
            stk.pop();
        }
        s2.push(x);
        while(!s2.empty()) {
            stk.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int e = stk.top();
        stk.pop();
        return e;
    }
    
    int peek() { return stk.top(); }
    
    bool empty() { return stk.empty();}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */