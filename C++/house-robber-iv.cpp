class Solution {
    //https://leetcode.com/problems/house-robber-iv
public:
    //#define DEBUG
    #ifndef DEBUG
        #define printf(...) empty_printf(__VA_ARGS__)
    #endif 
    #define empty_printf(...)
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%d,",i);printf("\n");
    
    int minCapability(vector<int>& nums, int k) {
        printf("\nminCapability, k= %d\n",k);
        print_container(nums);
        vector<int> A = nums;
        nums.push_back(INT_MAX);
        int n = nums.size();
        
        function<int(int)> check_cnt =  [&](int v) {
            //select all value that smaller or equal than v
            int cnt = 0;
            int L = 0;
            for(int R = 0;R<n;R++) {
                if(nums[R] > v) {//case of no select 
                    int w = R-L;
                    cnt+=(w+1)/2;
                    L=R+1;
                }
            }
            return cnt;
        };
        sort(A.begin(), A.end());
        
        for(int i = 0; i<A.size();i++) 
            printf("A[i=%d] = %d, check_cnt(%d) = %d\n",  i,A[i], A[i], check_cnt(A[i]));
        
        printf("Start to binary search\n");
        int L = 0, R=A.size()-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            printf("L,M,R = %d,%d,%d\n", L,M,R);
            if( (M-1<0 || check_cnt(A[M-1])<k) && check_cnt(A[M]) == k ) {
                printf("A[M=%d] = %d is solution\n",M, A[M]);
                return A[M];
            } 
            if(check_cnt(A[M]) >= k) {
                R=M-1;
            } else {
                L=M+1;
            }
        }
        return -1;
        
    }
};