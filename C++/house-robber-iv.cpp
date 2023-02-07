class Solution {
public:
    #define DEBUG
    #ifndef DEBUG
        #define printf(...) empty_printf(__VA_ARGS__)
    #endif 
    #define empty_printf(...)
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%d,",i);printf("\n");
    
    int minCapability(vector<int>& nums, int k) {
        return 0;
    }
    int minCapability_research(vector<int>& nums, int k) {
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
        for(auto &v: A) 
            printf("v = %d, check_cnt(v) = %d\n",  v, check_cnt(v));
    }
    /*
    Stdout:
    minCapability, k= 2
    nums = 2,3,5,9,
    v = 2, check_cnt(v) = 1
    v = 3, check_cnt(v) = 1
    v = 5, check_cnt(v) = 2
    v = 9, check_cnt(v) = 2
    Expected:
    5

    Stdout:
    minCapability, k= 2
    nums = 2,7,9,3,1,
    v = 1, check_cnt(v) = 1
    v = 2, check_cnt(v) = 2
    v = 3, check_cnt(v) = 2
    v = 7, check_cnt(v) = 2
    v = 9, check_cnt(v) = 3
    Expected:
    2

    Stdout:
    minCapability, k= 3
    nums = 2,7,9,3,1,
    v = 1, check_cnt(v) = 1
    v = 2, check_cnt(v) = 2
    v = 3, check_cnt(v) = 2
    v = 7, check_cnt(v) = 2
    v = 9, check_cnt(v) = 3
    Expected:
    9

    */
};