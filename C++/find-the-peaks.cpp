class Solution {
    //https://leetcode.com/problems/find-the-peaks
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        int n = mountain.size(); 
        mountain.push_back(INT_MAX);
        for(int i = 1;i<n-1;i++) 
            if(mountain[i]>mountain[i-1] && mountain[i]>mountain[i+1]) 
                ans.push_back(i++);//Make i go step 2 because the two peak cannot be neighbor.
        return ans;
    }
};