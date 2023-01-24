class Solution {
    //https://leetcode.com/problems/maximum-product-subarray
    //article https://leetcode.com/problems/maximum-product-subarray/discuss/2214438/C%2B%2B-or-2-approach-to-make-time-O(n)-space-O(1)-or-Explanation
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5454101964612250/
public:
    int maxProduct(vector<int>& nums) {
        
        //Observation
        //if no zero, the value max(abs(pos_max), abs(neg_max)) must grow 
        //in non-decreasing order when you keep going to multiply.
        //But think about the answer of this case [3,-1,4] is 4
        //travel it in backward from end and problem solve. 
        //
        //(1)We hope subproblem should keep track of the pos max & neg max 
        //(2)go to zero again when meet zero. pos_max and neg_max must zero together
        //
        
        int ans=INT_MIN;
        function<void(vector<int>&)> travel = [&ans](vector<int>& A){
            int n = A.size();
            int pos_max=0, neg_max=0;
            for(int i = 0;i<n;i++) {
                if(A[i] == 0) {
                    pos_max = neg_max = 0;
                } else {
                    if(pos_max==0) {//must neg_max==0 in the same time
                        pos_max = A[i];
                        neg_max = A[i];
                    } else {
                        pos_max*=A[i];
                        neg_max*=A[i];
                        if(pos_max<neg_max)swap(pos_max,neg_max);
                    }
                }
                ans = max(ans, pos_max);
            }            
        };
        
        travel(nums);
        reverse(nums.begin(), nums.end());
        travel(nums);
        
        return ans;
    }
    
    int maxProduct_v01(vector<int>& nums) {
        int ans = INT_MIN;
        int can = 1;
        for(auto &v: nums) {
            if(v!=0) {
                can*=v;
                ans=max(ans,can);
            } else {
                ans=max(ans,0);
                can = 1;
            }
        }
        reverse(nums.begin(), nums.end());
        can = 1;
        for(auto &v: nums) {
            if(v!=0) {
                can*=v;
                ans=max(ans,can);
            } else {
                ans=max(ans,0);
                can = 1;
            }
        }
        return ans;        
    }

    int maxProductByReferSolution(vector<int>& nums) {
        int ans=INT_MIN, max_chasing=1, min_chasing=1;
        for(auto &v: nums) {
            initializer_list<int> list = {v,max_chasing*v,min_chasing*v};
            min_chasing = min(list);
            max_chasing = max(list);
            ans = max(max_chasing,ans);
        }
        return ans;
    }
};