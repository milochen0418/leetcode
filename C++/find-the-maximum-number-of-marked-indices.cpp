class Solution {
    //https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/
public:
    //#define DEBUG
    #ifndef DEBUG
        #define printf(...) empty_printf(__VA_ARGS__)
    #endif 
    #define empty_printf(...)
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%3d,",i);printf("\n");

    int maxNumOfMarkedIndices(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans=0, n = A.size();
        int L=0, R=n/2;
        while(L<n && R<n) {
            if(A[R]<0) {
                R++;
            } else if(A[L]<0) {
                L++;
            } else if(A[L]*2<=A[R]) {
                ans+=2;
                A[L++]*=-1;
                A[R++]*=-1;
            } else { //D[i]>=A[j]
                R++;  
            }
        }
        return ans;        
    }

    int maxNumOfMarkedIndices_v01(vector<int>& nums) {
        vector<int>& A = nums; 
        int n = A.size();
        sort(A.begin(), A.end());
        vector<int> D = A;
        for(int i = 0; i<n;i++) D[i]*=2;        
        
        print_container(A);
        print_container(D);
        int ans = 0;
        unordered_set<int> mark;
        int L = 0, R=n/2;
        while(L<n && R<n) {
            if(mark.find(R) != mark.end()) {
                R++;
            } else if(mark.find(L) != mark.end()) {
                L++;
            } else if(D[L]<=A[R]) {
                ans+=2;
                mark.insert(L);
                mark.insert(R);
                L++;
                R++;
            } else { //D[i]>=A[j]
                R++;  
            }
        }
        return ans;
        
    }
};
/*
test case 
[3,5,2,4]
[9,2,5,4]
[42,83,48,10,24,55,9,100,10,17,17,99,51,32,16,98,99,31,28,68,71,14,64,29,15,40]
[57,40,57,51,90,51,68,100,24,39,11,85,2,22,67,29,74,82,10,96,14,35,25,76,26,54,29,44,63,49,73,50,95,89,43,62,24,88,88,36,6,16,14,2,42,42,60,25,4,58,23,22,27,26,3,79,64,20,92]
*/