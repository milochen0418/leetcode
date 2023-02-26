class Solution {
    //https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/
public:
    #define DEBUG
    #ifndef DEBUG
        #define printf(...) empty_printf(__VA_ARGS__)
    #endif 
    #define empty_printf(...)
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%3d,",i);printf("\n");    
    int maxNumOfMarkedIndices(vector<int>& nums) {
        
        vector<int>& A = nums; 
        int n = A.size();
        sort(A.begin(), A.end());
        vector<int> D = A;
        for(int i = 0; i<n;i++) D[i]*=2;
        
        
        /*
        [3,5,2,4] -> [2,3,4,5]
        (2,5), -> ans = 2
        [9,2,5,4] -> 
        
        [2,4, 5,9] nums[]   aka A
        [4,8,10,18] dnums[]( aka D) . find i<j s.t. dnums[i] < nums[j];
        find i<j s.t. D[i] < A[j];
        It's looke like two-pointer solution here
        
        (4,9), (2,4)
        [7,6,8] -> [6,7,8]
        */  
        
        /*
        A = [2,4, 5, 9] 
        D = [4,8,10,18] . 
        find i<j s.t. D[i] < A[j];
        */
        print_container(A);
        print_container(D);
        
        int ans = 0;
        unordered_set<int> mark;
        int i = n-1, j=n-1;
        while(i>=0 && j>=0) { 
            if(D[i]<=A[j]) {
                printf("(i,j) =(%d,%d), D[i]=%d < A[j]=%d\n", i,j,D[i],A[j]);
                
                if(mark.find(i) == mark.end()) {
                    mark.insert(i);    
                    ans++;
                }
                if(mark.find(j) == mark.end()) {
                    mark.insert(j);    
                    ans++;
                }
                //ans+=2;
                i--;
                j--;
                
            } else {//D[i]>=A[j]
                i--;
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