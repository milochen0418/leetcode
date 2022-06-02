class Solution {
    //https://leetcode.com/problems/find-the-distance-value-between-two-arrays
    //article https://leetcode.com/problems/find-the-distance-value-between-two-arrays/discuss/2103513/C%2B%2B-or-two-approaches-or-brute-force-binary-search
public:
    int findTheDistanceValue(vector<int>& values, vector<int>& a, int d) {
        sort(a.begin(),a.end());        
        int ans = 0;
        for(auto v:values){
            int L = 0, R = a.size() - 1;
            while(L <= R){
                int M = L + (R-L)/2;
                int aM_v = a[M] - v;
                if( -d<= aM_v && aM_v <=d) break;
                if(aM_v > d)
                    R = M - 1;
                else
                    L = M + 1;
            }
            ans+=(L>R);
        }
        return ans;
    }

    bool isValid(vector<int>&a,int offset,int d){
        int L = 0, R = a.size() - 1;
        while(L <= R){
            int M = L + (R-L)/2;
            int aM_v = a[M] - offset;
            if( -d<= aM_v && aM_v <=d) return false;
            if(aM_v > d)
                R = M - 1;
            else
                L = M + 1;
        }
        return true;
    }
    
    int findTheDistanceValueTwoFunction(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());        
        int ans = 0;
        for(auto num:arr1){
           if(isValid(arr2,num,d)) ans++;
        }
        return ans;
    }

    int findTheDistanceValueBruteForce(vector<int>& arr1, vector<int>& arr2, int d) {
        int err = 0;
        for(int i= 0;i<arr1.size();++i){
            for(int j = 0;j<arr2.size();++j){
                if(abs(arr1[i]-arr2[j])<=d){
                    err++;
                    break;
                }
            }
        }
        return arr1.size() - err;
    }

};