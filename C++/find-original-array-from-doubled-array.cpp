class Solution {
    //https://leetcode.com/problems/find-original-array-from-doubled-array
    //add article https://leetcode.com/problems/find-original-array-from-doubled-array/discuss/2577489/C%2B%2B-or-Sort-%2B-Hash-Map-or-explanation
public:
    vector<int> findOriginalArray(vector<int>& changed) { 
        //assume changed = [0,0,1,1,3,4,2,2,6,8]
        vector<int> ans = vector<int>(); 
        unordered_map<int,int> mp; 
        for(auto &i: changed) mp[i]++;  //mp will be  {(0,2),(1,2),(2,2) (3,1),(4,1),(6,1),(8,1)}
        vector<int> v = vector<int>();
        for(auto &[k,val]:mp) v.push_back(k); 
        sort(v.begin(), v.end());//v will be {0,1,2,3,4,6,8} here 
        
        if(mp[0]%2!=0) return vector<int>();//edge case for zero
        
        for(auto &i: v) {
            if(i!=0) {
                if(mp[i]>mp[i*2]) return vector<int>();
                for(int j=0;j<mp[i];j++) ans.push_back(i);
                mp[i*2] -= mp[i];
                mp[i] = 0;
            } else {
                //edge case for zero
                for(int j =0;j<mp[i]/2;j++) ans.push_back(i);
            }
        } 
        return ans;
    }
};