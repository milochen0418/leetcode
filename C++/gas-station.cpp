class Solution {
    //https://leetcode.com/problems/gas-station
    /*
        My research note of this question.
        [1, 2, 3, 4, 5]
        [3, 4, 5, 1, 2]

        [1,  2,  3,  4,  5]
        [3,  4,  5 , 1,  2]
        -2 -2   -2  +3  +3

        answer = 3 

        [2,3,4]
        [3,4,3]

        [2, 3, 4]
        [ 3, 4, 3]
        -1 -2  1



        [5,8,2,8]
        [6,5,6,6]


        gas [5, 8, 2, 8]
        cost[ 6, 5, 6, 6]
        m    -1 +3 -4 +2
        mm   +3 +4 -7 +6

        mm[4] = m[4] - m[3]
        m[4] = gas[4] - cost[4]
        m[3] = gas[3] - cost[3]

        so m[4] - m[3] = (gas[4] - cost[4]) - (gas[3] - cost[3])
        = (gas[4]-gas[3]) - (cost[4]-cost[3])    
    */
public:
    int new_answer(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int sum = 0;
        int max_val=INT_MIN;
        int max_idx=-1;
        for(int i=0; i < n; i++) {
            sum+= (gas[i]-cost[i]);
            int next = (i+1)%n;
            int dist = (gas[next]-cost[next])-(gas[i]-cost[i]);
            if(max_val < dist) {
                max_val = dist;
                max_idx = next;
            }
        }
        return sum<0?-1:max_idx;        
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return new_answer(gas,cost);
        
        
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