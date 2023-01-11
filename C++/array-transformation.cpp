class Solution {
    //https://leetcode.com/problems/array-transformation/
public:
    vector<int> transformArray(vector<int>& arr) {
        vector<int>& A = arr;
        int n = A.size();
        vector<int> zeroD = vector<int>(n,0), D=zeroD ;
        do{
            D = zeroD;
            for(int i =1;i<n-1;i++) {
                if(A[i-1]>A[i]&&A[i]<A[i+1]) D[i]=1;
                if(A[i-1]<A[i]&&A[i]>A[i+1]) D[i]=-1;
            }
            for(int i = 1;i<n-1;i++) A[i]+=D[i];
        }while(zeroD != D);
        return A;
    }
};