class MyStack {
    //https://leetcode.com/problems/implement-stack-using-queues/
public:
    vector<queue<int>> qs;
    int qidx;
    MyStack() {
        qs = vector<queue<int>> (2,queue<int>());
        qidx = 0; 
        /*
        Simulate stack push
           q1     q2
         ---------------
           [1]    []
           q2.push(2)
           q2.pushall(q1)  
           []     [2<-1]
           q1.push(3)
           q1.pushall(q2)
           [3<-2<-1] []
           q2.push(4)
           q2.pushall(q1)
           [] [4<-3<-2<-1]
        */
        
    }
    
    void push(int x) {
        queue<int> &prev_q = qs[qidx];
        qidx = (qidx+1)%2;
        qs[qidx].push(x);
        while(!prev_q.empty()) {
            int e =prev_q.front();
            prev_q.pop();
            qs[qidx].push(e);
        }        
    }
    
    int pop() {
        int ret = qs[qidx].front();
        qs[qidx].pop();
        return ret;
    }
    
    int top() {
        int ret = qs[qidx].front();
        return ret;
    }
    
    bool empty() {
        return qs[qidx].empty();
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