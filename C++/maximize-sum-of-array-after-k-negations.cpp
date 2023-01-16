class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> negMinQ;
        priority_queue<int, vector<int>, greater<int>> posMinQ;
        
        int sum = 0;
        for(auto &i:nums) {
            (i<0?negMinQ:posMinQ).push(i);
            sum+=i;
        }
        
        while(k-->0) {
            if(!negMinQ.empty()) {
                int e = negMinQ.top();
                negMinQ.pop();
                sum -= 2*e;
                posMinQ.push(-1*e);
            } else if(!posMinQ.empty()) {
                int e = posMinQ.top();
                posMinQ.pop();
                sum -= 2*e;
                negMinQ.push(-1*e);
            }
        }
        return sum;
        
        
    }
};