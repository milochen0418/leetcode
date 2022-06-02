class Solution {
    
public:
    bool isValid(vector<int>&a,int v,int d){
        
        int L = 0, R = a.size() - 1;
        while(L <= R){
            int M = L + (R-L)/2;
            int t = a[M] - v;
            if( -d<=t &&t<=d) return false;
            if(t > d)
                R = M - 1;
            else
                L = M + 1;
        }
        return true;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(),arr2.end());
        
        int cnt = 0;
        for(auto num:arr1){
           if(isValid(arr2,num,d)){
               cnt++;
           } 
        }
        
        return cnt;
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