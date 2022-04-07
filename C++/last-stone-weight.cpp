class Solution {
    //https://leetcode.com/problems/last-stone-weight
public:
    int lastStoneWeight(vector<int>& stones) {
        //return answer1(stones);
        priority_queue<int> maxQ;
        for(auto &i:stones) maxQ.push(i);
        while(maxQ.size()>1) {
            int e1 = maxQ.top();
            maxQ.pop();
            e1 -= maxQ.top();
            maxQ.pop();
            if(e1>0) maxQ.push(e1);
        }
        return maxQ.empty()?0:maxQ.top();
    }
    int answer1(vector<int>& stones) {
        int stones_size = stones.size();        
        while(stones_size>1) {
            
            sort(stones.begin(), stones.end(),greater<int>());
            //for(auto &i:stones) cout<<", "<<i;cout<<" size="<<stones_size<<"\n";
            int minus = stones[1];
            stones[0] -= minus;
            stones[1] -= minus;
            if(stones[0]==0) {
                stones_size-=2;
            } else {
                stones_size-=1;
            }            
        }
            
        if(stones_size==1){
            //return stones[0];
            return *max_element(stones.begin(), stones.end());
        } else {
            return 0;
        } 
    }
    
};