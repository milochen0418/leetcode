class Solution {
    //https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks
    //article https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/discuss/2994957/C%2B%2B-Hash-Map-or-explanation  
public:
    int minimumRounds(vector<int>& tasks) {
        //Observation
        //1: x
        //2: 1
        //3: 1
        
        //4: 2 (2+2)
        //5: 2 (3+2)
        //6: 2 (3+3)
        
        //7: 3 (3+2+2)
        //8: 3 (3+3+2)
        //9: 3 (3+3+3)
        
        //10:4 (3+3+2+2)
        //11:4 (3+3+3+2)
        //12:4 (3+3+3+3)
        
        //13:5 (3+3+3+2+2)
        //14:5 (3+3+3+3+2)
        //15:5 (3+3+3+3+3)
        
        /*
        if(i==1) then false
        otherwise, round=1+(i-1)/3
        */
        
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto &t:tasks) mp[t]++;
        for(auto &[k,v]:mp) {
            if(v==1) return -1;
            ans+=1+(v-1)/3;
        }
        return ans;
    }
};