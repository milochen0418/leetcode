/*

["G","P","GP","GG"], travel = 
    2,  4,   3

ans = 0
ans += (1+1+2+2)    -> ans=6



M: ans+= 0  -> ans=0
G: ans+= (2+3+4) -> ans is 15
P: ans+= (2+4) -> ans is 21

//Step 1. ans += all number of trash 
//Step 2. ans += all travel time of different kind of truck 



  G,M,P  

Output: 21

*/

class Solution {
    //https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        /*
        vector<int> presum = travel;
        for(int i = 1;i<presum.size();i++) presum[i] = presum[i-1] + presum[i];
        */
        map<char,int> maxIdx;
    
        for(int i = 0; i < garbage.size();i++) {
            for(int j = 0;j<garbage[i].length();j++) {
                char c = garbage[i][j];
                maxIdx[c] = i;
            }
        }
        
        
        
        for(int i = 0; i < garbage.size();i++) {
            ans+=garbage[i].length();
        }
        
        for(auto& [c,maxidx] : maxIdx) {
            for(int i = 0; i<=maxidx;i++) {
                if(i>0) {
                    ans+=travel[i-1];    
                }
            }            
        }
        
        
        return ans;
    }
};