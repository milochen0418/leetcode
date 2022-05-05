class MyStack {
    //https://leetcode.com/problems/implement-stack-using-queues/
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        /*
        Simulate stack push
           q1     q2
         ---------------
           [1]    []
           q2.clean()
           q2.push(2)
           q2.pushall(q1)  
           []     [2<-1]
           q1.clean()
           q1.push(3)
           q1.pushall(q2)
           [3<-2<-1] []
           q2.clean()
           q2.push(4)
           q2.pushall(q1)
           [] [4<-3<-2<-1]
        */
        
    }
    
    void push(int x) {
        
    }
    
    int pop() {
        
    }
    
    int top() {
        
    }
    
    bool empty() {
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */