class Solution {
    //https://leetcode.com/problems/counting-elements
public:
    int countElements(vector<int>& arr) {
        vector<int>& A = arr;
        int ans = 0, n = A.size();
        sort(A.begin(), A.end());
        int accu = 1;
        for(int i = 1; i<n;i++) {
            if(A[i-1]+1 == A[i]) ans+=accu; 
            accu = A[i-1]==A[i]?accu+1:1;
        }
        return ans;
    }

    int countElements_hashset(vector<int>& arr) {
        unordered_set<int> s;
        for(auto &i:arr) s.insert(i);
        int ans = 0;
        for(auto &i:arr) if(s.find(i+1)!=s.end()) ans++;
        return ans;
    }
};