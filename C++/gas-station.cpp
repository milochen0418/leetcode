class Solution {
    //https://leetcode.com/problems/gas-station
public:
    int test(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int t = 0;
        int max_val=INT_MIN;
        int max_idx=-1;
        for(int i=0,j=1; i < n; i++,j=(j+1)%n) {
            t+= (gas[i]-cost[i]);
            int dist = (gas[j]-cost[j])-(gas[i]-cost[i]);
            if(max_val < dist) {
                max_val = dist;
                max_idx = j;
            }
        }
        return t<0?-1:max_idx; 
        
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //return test(gas,cost);
        int n = cost.size();
        int t = 0;
        int max_val=INT_MIN;
        int max_idx=-1;
        for(int i=0; i < n; i++) {
            t+= gas[i];
            t-=cost[i];
        }
          
        if(t<0) return -1;
        vector<int>minus(n);
        vector<int>miminus(n);
        for(int i=0;i<n;i++){
            minus[i] = gas[i] - cost[i];
        }
        for(int i=0;i<n;i++){
            int next = (i+1)%n;
            miminus[next] = minus[next] -  minus[i];
        }
        for (int i=0;i<n;i++) {
            if(miminus[i]>max_val) {
                max_val = miminus[i];
                max_idx = i;
            }
        }
        return max_idx;
     
    }
};