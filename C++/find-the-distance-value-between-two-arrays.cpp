class Solution {
    
public:
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
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
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