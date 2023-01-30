class Solution {
    //https://leetcode.com/problems/count-largest-group/
public:
    //#define DEBUG
    #ifndef DEBUG
        #define printf(...) empty_printf(__VA_ARGS__)
    #endif 
    #define empty_printf(...)    
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%d,",i);printf("\n");
    int countLargestGroup(int n) {
        unordered_map<int,vector<int>> mp;
        int maxv = 0;
        for(int i = 1;i<=n;i++) {
            int m = i;
            int dsum = 0;
            while(m>0) {
                dsum += m%10;
                m/=10;
            }
            mp[dsum].push_back(i);
            maxv= max(maxv,(int)mp[dsum].size());
        }
        printf("maxv=%d\n",maxv);
        int ans = 0;
        for(auto &[k,v]:mp) {
            printf("dsum=%d:", k);
            print_container(mp[k]);
            
            if(maxv==v.size()) {
                ans++;
            }
        }
        return ans;
    }
};