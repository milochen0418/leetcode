class Solution {
    //https://leetcode.com/problems/closest-prime-numbers-in-range/submissions/
public:
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...) 

    vector<int> closestPrimes(int left, int right) {
        vector<int> is_primes = vector<int>(right+1,1);
        vector<int> primes=vector<int>(), ans=vector<int>(2,-1);
        if(left<=2 && right>=3) return {2,3};
        
        is_primes[0] = is_primes[1] = 0;
        int sqrt_right=sqrt(right);
        for(int i = 3;i<=sqrt_right;i+=2) {
            if(is_primes[i]==1) {
                if(i-2>=left && is_primes[i-2]==1)  return {i-2,i};
                for(int j = i+(i+i);j<=right;j+=(i+i)) {
                    is_primes[j] = 0;
                    
                }                
            }
        }
        int min_gap = INT_MAX;
        
        printf("primes = ");
        if(left%2==0) left+=1;
        for(int i = left;i<=right;i+=2) {
            //if(i%2==0) continue;
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
        return vector<int>{-1,-1};
    }
    
    vector<int> closestPrimes_v03(int left, int right) {
        vector<int> is_primes = vector<int>(right+1,1);
        vector<int> primes=vector<int>(), ans=vector<int>(2,-1);
        if(left<=2 && right>=3) return {2,3};
        
        is_primes[0] = is_primes[1] = 0;
        int sqrt_right=sqrt(right);
        for(int i = 3;i<=sqrt_right;i+=2) {
            if(is_primes[i]==1) {
                for(int j = i+(i+i);j<=right;j+=(i+i)) {
                    is_primes[j] = 0;
                }                
            }
        }
        int min_gap = INT_MAX;
        
        printf("primes = ");
        if(left%2==0) left+=1;
        for(int i = left;i<=right;i+=2) {
            //if(i%2==0) continue;
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
        return vector<int>{-1,-1};
    }


    vector<int> closestPrimes_v02(int left, int right) {
        vector<int> is_primes = vector<int>(right+1,1);
        vector<int> primes=vector<int>(), ans=vector<int>(2,-1);
        if(left<=2 && right>=3) return {2,3};
        
        is_primes[0] = is_primes[1] = 0;
        for(int i = 3;i<=right;i+=2) {
            if(is_primes[i]==1) {
                for(int j = i+(i+i);j<=right;j+=(i+i)) {
                    is_primes[j] = 0;
                }                
            }
        }
        int min_gap = INT_MAX;
        
        printf("primes = ");
        if(left%2==0) left+=1;
        for(int i = left;i<=right;i+=2) {
            //if(i%2==0) continue;
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
        return vector<int>{-1,-1};
    }

    vector<int> closestPrimes_v01(int left, int right) {
        //vector<int> is_primes = vector<int>(right+1,1);
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
        return vector<int>{-1,-1};
    }
};