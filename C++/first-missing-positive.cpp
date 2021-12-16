class Solution {
    //https://leetcode.com/problems/first-missing-positive
public:
    int firstMissingPositive(vector<int>& nums) {
        //Interesting of the scope of solution ?
        //The largest solution of missing positive will be n since size of nums[] is n.
        //And the case will be like
        //it mean nums[0]=1, nums[1]=2, ..., nums[n-1] = n or any arrangement of this sequence. 
        //
        //What about that one number is missing in this case? 
        //for example,there is only one k in 1<=k<=n s.t. nums[k-1] != k 
        //Then k is missing positive. 
        
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums,i, nums[i]-1);
            }
        }


        


        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1 ) {
                return i+1;
            }
        }
        return n+1;
    }

private:
    void swap(vector<int>& v, int a, int b) {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
    }
};