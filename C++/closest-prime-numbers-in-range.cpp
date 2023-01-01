class Solution {
    //https://leetcode.com/problems/closest-prime-numbers-in-range/
public:
    
    #define printf(...) empty_printf(__VA_ARGS__)
    void empty_printf(const char *fmt, ...) {
        /*
        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
        */
    }
    
    vector<int> closestPrimes(int left, int right) {
        vector<int> is_primes = vector<int>(right+1,1);
        vector<int> primes=vector<int>(), ans=vector<int>(2,-1);
        is_primes[0] = is_primes[1] = 0;
        for(int i = 2;i<=right;i++) {
            if(is_primes[i]==1) {
                for(int j = i+i;j<=right;j+=i) {
                    is_primes[j] = 0;
                }                
            }
        }
        int min_gap = INT_MAX;
        
        printf("primes = ");
        for(int i = left;i<=right;i++) {        
            if(is_primes[i]==1) {
                printf("%d,",i);
                if(primes.size()>0) {
                    int gap = i - primes.back();
                    if(gap<min_gap) {
                        printf("gap<min_gap, gap = %d, min_gap = %d\n", gap, min_gap);
                        min_gap = gap;
                        ans[0] = primes.back();
                        ans[1] = i;
                        if(min_gap==2) return ans;
                    }
                }
                primes.push_back(i);
            }
        }
        printf("\n");
        if(ans[0]!=-1)return ans;
        return vector<int>{-1,-1};=
    }
};