class Solution {
    //https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays
    //article https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/discuss/4179163/C%2B%2B-or-One-Pass-O(N)-or-simple-15-lines
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans = {0};
        if(A[0] == B[0]) ans[0] = 1;
        unordered_set<int> sA={A[0]}, sB={B[0]};
        for(int i = 1; i<n; i++) {
            int tmp = 0;
            int valA = A[i], valB = B[i];
            if(sA.find(valA) == sA.end()) 
                if(sB.find(valA) != sB.end()) tmp++;
            if(sB.find(valB) == sB.end()) 
                if(sA.find(valB) != sA.end()) tmp++;
            if(valA == valB) 
                if(sA.find(valA) == sA.end() && sB.find(valB) == sB.end())  tmp++;
            sA.insert(valA);
            sB.insert(valB);
            ans.push_back(ans.back() + tmp);
        }
        return ans;
        
    }
};