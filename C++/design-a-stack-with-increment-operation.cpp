class CustomStack {
    //https://leetcode.com/problems/design-a-stack-with-increment-operation
public:
    vector<int> stk;
    int stk_size = 0;
    int max_stk_size =0;
    CustomStack(int maxSize) {
        stk_size = 0;
        max_stk_size = maxSize;
    }
    
    void push(int x) {
        if(stk_size<max_stk_size) {
            stk.push_back(x);
            stk_size++;
        }
    }
    
    int pop() {
        
        if(stk_size>0) {
            int ret = stk.back();
            stk.pop_back();
            stk_size--;
            return ret;
        }
        else {
            return -1;
        }
    }
    
    void increment(int k, int val) {
        int n = min(stk_size, k);
        for(int i = 0; i<n; i++)
            stk[i] += val ;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */