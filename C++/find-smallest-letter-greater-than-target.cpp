class Solution {
    //https://leetcode.com/problems/find-smallest-letter-greater-than-target/
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>&a = letters;
        char t = target, ans;
        int L = 0, R=a.size()-1;
        while(L<=R) {
            int M = L+ (R-L)/2;
            if(a[M] > t && (M-1<0 || a[M-1]<=t) ){
                return a[M]; //case searching matched
            }
            if(target>=a[M]) 
                L = M+1; //case search right-side
            else 
                R = M-1;//case search left-side
        }
        return a[0];
    }

    char nextGreatestLetterOld(vector<char>& letters, char target) {
        vector<char> v;
        for(auto& c:letters) if(v.size()==0 || v.back()!=c)v.push_back(c);
        
        int n=v.size(), L = 0, R=n-1;
        if(target > v[R]) return v[L];
        while(L<=R) {
            int M = L + (R-L)/2;
            if(target >v[M]) {
                L=M+1;
            } else if(target< v[M]) {
                R=M-1;
            } else {
                return M+1<n?v[M+1]:v[0];
            }
        }
        return v[L];
    }    
};