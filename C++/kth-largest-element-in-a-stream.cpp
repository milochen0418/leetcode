class KthLargest {
    //https://leetcode.com/problems/kth-largest-element-in-a-stream
public:
    priority_queue<int, vector<int>, greater<int>> minQ;
    int maxsize = 0;
    KthLargest(int k, vector<int>& nums) {
        maxsize = k;
        for(auto& i:nums) minQ.push(i);
        while(minQ.size() > k) minQ.pop();
        //printMinQ(minQ);  
    }
    void printMinQ(priority_queue<int, vector<int>, greater<int>>& minQ){
        vector<int> v;
        
        while(!minQ.empty()) {
            int top = minQ.top();
            cout<<", "<<top;
            v.push_back(top);
            minQ.pop();
        }
        cout<<"\n";
        for(auto& i:v) minQ.push(i);
    }
    
    
    int add(int val) {
        minQ.push(val);
        if(minQ.size() > maxsize) minQ.pop();
        //printMinQ(minQ);
        int ret = minQ.top();
        //cout<<"ret ="<<ret<<"\n";
        return ret;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */