class Solution {
    //https://leetcode.com/problems/find-smallest-letter-greater-than-target/
    //article https://leetcode.com/problems/find-smallest-letter-greater-than-target/discuss/2109778/C%2B%2B-or-simple-binary-search-solution-or-explanation
    //article https://leetcode.com/problems/find-smallest-letter-greater-than-target/discuss/2155245/C%2B%2B-or-return-aM-s.t.-M-in-LR-satisfy-aMgreatertgreateraM-1
public:
    char nextGreatestLetter(vector<char>& a, char t) {
        int n=a.size(), L = 0, R=n;
        while(L<=R) { // return a[M] s.t. M in [L,R] satisfy a[M]>t>=a[M-1]
            int M = L + (R-L)/2;
            if( (M==n||a[M]>t) && (M-1<0||t>=a[M-1]) ) return a[M%n];
            if(t>=a[M]) L=M+1; else R=M-1;
        } return '\0';
    }

    char nextGreatestLetterAnswer2(vector<char>& letters, char target) {
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
                //Use target>=a[M] to instead target>a[M] because of following case
                //["e","e","e","e","e","e","n","n","n","n"]
                //"e"
            else 
                R = M-1;//case search left-side
        }
        return a[0];
    }

    char nextGreatestLetterAnswer1(vector<char>& letters, char target) {
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