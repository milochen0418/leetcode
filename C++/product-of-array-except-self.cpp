class Solution {
    //https://leetcode.com/problems/product-of-array-except-self
    //https://leetcode.com/problems/product-of-array-except-self/discuss/1743372/C%2B%2B-or-simple-time-O(N)-space-O(1)-or-only-use-for-and-if
/* testcase 
[1,2,3,4]
[-1,1,0,-3,3]
*/    
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        return approach2(nums);
        int n = nums.size();
        long product = 1;
        bool is_exist_zero = false;
        int only_zero_idx = -1;
        bool is_exist_two_zero = false;
        for(int i = 0; i<n;i++) {
            int num = nums[i];
            if(!is_exist_zero) {
                if(num ==0) {
                    is_exist_zero = true;
                    only_zero_idx = i;
                } else {
                    product *= (long)num;
                }
            } else if(is_exist_zero){ //case is_exist_zero
                if(num == 0) {
                    is_exist_two_zero = true;    
                } else {
                    product *= (long)num;
                }
                if(is_exist_two_zero) {
                    break;
                }
            } 
        }
        vector<int> ans(n,0);
        if(is_exist_two_zero) {
            return ans;            
        }else if(is_exist_zero) {
            ans[only_zero_idx] = product;
            return ans;
        } else {
            for(int i=0;i<n;i++) {
                ans[i] = (product/nums[i]);
            }
            return ans;            
        }          
    }
    vector<int> approach2(vector<int>& nums) {
        int n = nums.size();
        //nums = [ 1, 2, 3, 4]
        vector<int> ans(n);
        int product = 1;
        for(int i = 0;i<n;i++) {
            ans[i]=product;
            product*=nums[i];
        }
        //ans = [ 1, 1, 2, 6]
        product = 1;
        for(int i = n-1;i>=0;i--) {
            ans[i]*=product;
            product*=nums[i];
        }
        //[ 1, 1, 2, 6] 
        //    x
        //[24,12, 4, 1]
        //     ||
        //[24,12, 4, 1]

        return ans;
    }

};