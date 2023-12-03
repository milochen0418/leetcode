class Solution {
    //https://leetcode.com/problems/find-the-peaks
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        mountain.push_back(INT_MAX);
        for(int i = 1;i<mountain.size()-1;i++) 
            if(mountain[i]>mountain[i-1] && mountain[i]>mountain[i+1]) 
                ans.push_back(i);
        return ans;
    }
};