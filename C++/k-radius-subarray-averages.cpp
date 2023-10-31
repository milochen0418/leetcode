class Solution {
    //https://leetcode.com/problems/k-radius-subarray-averages
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        typedef long long ll;
        int L=0,R=k+k,C=k, n = nums.size();
        ll sum=0;
        if(R>=n) return vector<int>(n,-1); //edge case
        vector<ll> sums = vector<ll>(n,-1); 
        for(int i = L; i<=R;i++) sum += (ll)nums[i];
        sums[k] = sum;
        L++, R++, C++;
        while(R<n) {
            sum+=(ll)nums[R];
            sum-=(ll)nums[L-1];
            sums[C] = sum;
            L++, R++, C++;
        }
        /*
        printf("sum = ");
        for(int i = 0; i<n; i++) 
            printf("%ld, ", sums[i]);
        printf("\n");
        */
        vector<int>& ans= nums;
        ll width = 2*k+1;
        for(int i = 0; i<n; i++) {
            if(sums[i]==-1)
                nums[i] = -1;
            else
                nums[i] = (int)( sums[i] /(2*k+1));
        }
        return nums;
    }
};