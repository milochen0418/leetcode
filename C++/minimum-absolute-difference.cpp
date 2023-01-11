class Solution {
    //https://leetcode.com/problems/minimum-absolute-difference
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mingap = INT_MAX;
        for(int i = 1;i<n;i++) 
            mingap = min(mingap, arr[i] - arr[i-1]);
        
        for(int i = 1;i<n;i++) 
            if(mingap == arr[i] - arr[i-1]) 
                ans.push_back({arr[i-1],arr[i]});
        return ans;   
    }
};