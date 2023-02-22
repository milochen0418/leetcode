class Solution {
    //https://leetcode.com/problems/capacity-to-ship-packages-within-d-days
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxv = 0, sum = 0;
        for(auto &w:weights) {
            maxv = max(w,maxv);
            sum += w;
        }
        weights.push_back(INT_MAX/2);//dummy
        int L = maxv, R = sum;
        for(int i = L;i<=R;i++) {
            if(!check(weights, days, i)){
                return i;//return i when find out first false checkint result
            }
            /*
            printf("i=%d -> ",i);
            if(check(weights, days, i)) {
                printf("true\n");
            } else {
                printf("false\n");
            }
            */
        }
        return 0;
    }
    int check(vector<int>& weights, int days, int capacity) {
        int n = weights.size();
        int sum = 0;
        for(int i = 0; i<n-1;i++) {
            sum += weights[i];
            if(sum + weights[i+1] > capacity) {
                days--;
                sum = 0;
                if(days<0) return 1;
            }
        }
        return 0;
        
    }
};