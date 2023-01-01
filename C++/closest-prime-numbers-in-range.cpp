class Solution {
    //https://leetcode.com/problems/closest-prime-numbers-in-range/
public:
    vector<int> closestPrimes(int left, int right) {
        //int n = right;
        int n = right;
        set<int> primes;
        set<int> primess;
        for(int i = 2;i<=n;i++) primes.insert(i);
        
        int prev_min_p = -1;
        int min_gap = INT_MAX;
        vector<int> ans={-1,-1};
        
        while(1) {
            int min_p = findMin(primes);
            if(min_p==-1) break;
            //primess.insert(min_p);
            for(int i = min_p; i <= n; i+=min_p) primes.erase(i);
            
            
            if(prev_min_p>=left) {
                int gap = min_p - prev_min_p;
                if(gap < min_gap) {
                    min_gap = gap;
                    ans[0]=prev_min_p;
                    ans[1]=min_p;
                    printf("new gap found %d,%d\n", ans[0], ans[1]);
                }
                if(min_gap==2) return ans;
            }
            prev_min_p = min_p;            
        }
        /*
        printf("primess = ");
        for(auto &i:primess) printf("%d,",i);
        printf("\n");
        */
        if(min_gap == -1) return vector<int>{-1,-1};        
        return ans;

    }
    
    int findMin(set<int> my_set) {
        int min_element=-1;
        if (!my_set.empty())
            min_element = *my_set.begin();
        return min_element;
    }
 
};