class Solution {
    //https://leetcode.com/problems/maximum-sum-circular-subarray/
    //article https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/2215798/C%2B%2B-or-Can-any-test-case-make-this-greedy-algorithm-fail-or-TC-O(n)-SC-O(1)
    //FB post https://www.facebook.com/groups/1451299754892511/posts/5455204947835285/
    //Prefix Sum solution article https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/3069202/C%2B%2B-Prefix-Sum-O(N)
    

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int mini = extreSum(nums, true);
        int maxi = extreSum(nums, false);
        return total==mini ? maxi : max(maxi, total - mini);
        //This idea of solution is given in FB post discussion by Arthur Lin. 
    }

    int maxSubarraySumCircular_prefixSum_LTE(vector<int>& nums) {
        //prefix sum solution but LTE
        int sum = 0, n = nums.size();
        for(auto &i:nums) sum+=i;
        for(int i = 1;i<n;i++) nums[i]+=nums[i-1]; //prefix sum
        int ans = sum;
        for(int i=0;i<n;i++) {
            for(int j = i;j<n;j++) {
                if(i==0 && j==n-1) continue;//the case is sum, default in ans.
                int nums_i_1 = i==0?0:nums[i-1];
                int sum_i_j = nums[j] - nums_i_1; //sum[i..j]
                int q = max(sum_i_j,sum-sum_i_j);
                //printf("sum[%d..%d]=%d, sum-sum[i..j]=%d\n",i,j,sum_i_j, sum-sum_i_j);
                ans = max(q, ans);
            }
        }
        return ans;
    }
    int extreSum (vector<int>& a, bool is_min) {
        int sign =  is_min?-1:1;
        int ans = INT_MIN, R=0, acc=0;
        while (R<a.size()) {
            acc += (sign*a[R++]);
            ans = max(ans, acc);
            if(acc<0) acc = 0;
        }
        return sign*ans;// min/max subarray sum
        
    } //find minimum subarray sum or maximum subarray sum. 

    int maxSubarraySumCircularMayNeedMoreTestCase(vector<int>& nums) {
        vector<int>& a = nums;
        int n = a.size()*2;
        int w = a.size();
        int L,R,acc;
        int ans = INT_MIN;
        L=0;R=0;acc =0;
        while(L<n && R<n ) {
            acc = acc + a[R%w];
            ans = max(ans, acc);
            if(acc<0) {
                L=R+1;
                R=R+1;
                acc = 0;
            } else {
                R=R+1;
            }
            
            if(R-L+1>w) { 
                if(a[L%w]<0 || (L+1<n&& a[L%w]==a[(L+1)%w])) {
                    acc = acc - a[L%w];
                    L=L+1;                    
                } else {
                    R=L+1;
                    L=L+1;
                    acc = 0;   
                }
            }
        }
        return ans;
    }
    int maxSubarraySumCircularDirtyWithNSpace(vector<int>& nums) {
        vector<int> a;
        for(auto &i:nums) a.push_back(i);
        for(auto &i:nums) a.push_back(i);
        int n = a.size();
        int w = a.size()/2;
        int L,R,acc;
        int ans = INT_MIN;
        L=0;R=0;acc =0;
        while(L<n && R<n ) {
            acc = acc + a[R];
            ans = max(ans, acc);
            if(acc<0) {
                L=R+1;
                R=R+1;
                acc = 0;
            } else {
                R=R+1;
            }
            
            if(R-L+1>w) { //dirty work but don't know why pass all testcase
                if(a[L]<0 || (L+1<n&& a[L]==a[L+1])) {
                    acc = acc - a[L];
                    L=L+1;                    
                } else {
                    R=L+1;
                    L=L+1;
                    acc = 0;   
                }
            }
        }
        return ans;
    }


    int maxSubarraySumCircularLTE(vector<int>& nums) {
        vector<int> a;
        for(auto &i:nums) a.push_back(i);
        for(auto &i:nums) a.push_back(i);
        int n = a.size();
        int w = a.size()/2;
        int L,R,acc;
        int ans = INT_MIN;
        L=0;R=0;acc =0;
        while(L<n && R<n ) {
            acc = acc + a[R];
            ans = max(ans, acc);
            if(acc<0) {
                L=R+1;
                R=R+1;
                acc = 0;
            } else {
                R=R+1;
            }
            
            if(R-L+1>w) {
                /*
                acc = acc - a[L];
                L=L+1;
                */
                R=L+1;
                L=L+1;
                acc = 0;
            }
        }
        return ans;
    }
};