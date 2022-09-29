class Solution {
    //https://leetcode.com/problems/find-k-closest-elements
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end(), [&](auto &a, auto &b){
            if(abs(a-x) == abs(b-x)) {
                return a<b;
            } else {
                return abs(a-x) < abs(b-x);
            }            
        });
        for(int i = 0; i<k;i++) ans.push_back(arr[i]);
        sort(ans.begin(), ans.end());
        return ans;                
    }
};