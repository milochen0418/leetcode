class MinStack {
    //https://leetcode.com/problems/min-stack
public:
    vector<int> stk;
    vector<int> min; //The stack to save idx of min value in stk
    MinStack() {
    }
    
    void push(int val) {
        int min_idx = stk.size();
        stk.push_back(val);
        if(min.empty()) {
            min.push_back(min_idx);
        } else {
            //while(min.back()>=stk.size())min.pop_back();
            if(val<stk[min.back()]) 
                min.push_back(min_idx);
        }
    }
    
    void pop() {
        stk.pop_back();
        while( !min.empty() && min.back()>=stk.size())min.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        //while(min.back()>=stk.size())min.pop_back();
        return stk[min.back()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */