class Solution {
    //https://leetcode.com/problems/count-good-triplets
public:
    int a,b,c;
    int countGoodTriplets(vector<int>& arr, int _a, int _b, int _c) {
        a=_a, b=_b, c=_c;
        int ans=0,  n = arr.size();
        for(int i =0;i<n;i++)
            for(int j =i+1;j<n;j++)
                for(int k=j+1;k<n;k++) 
                    if(is_good_triplets(arr,i,j,k))
                        ans++;
         return ans;       
    }
    
    bool is_good_triplets(vector<int>& A, int i, int j, int k) {
        return  
            (abs(A[i] - A[j]) <= a) 
            &&(abs(A[j] - A[k]) <= b) 
            && (abs(A[i] - A[k]) <= c);             
    }
};