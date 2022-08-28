class Solution {
    //https://leetcode.com/problems/longest-subsequence-with-limited-sum/
public:
    //1,2,4,5 
    //3,10,21
    //2:1+2 -> 3
    //3: 1+2+4 ->10
    //4:1+2+4+5 -> 21
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        int n = nums.size();
        vector<int> ans = vector<int>(queries.size(), 0);
        //[4,5,2,1]
        sort(nums.begin(), nums.end());
        //[1,2,4,5]
        //figure prefixsum
        for(int i = 1;i<nums.size();i++) {
            nums[i] = nums[i-1] + nums[i];
        }
        //queries = [3,10,21]
        //nums =    [1,3,7,12]
        //ans     = [2, 3, 4]
        
        
        /*
        printf("nums[]=");
        for(auto &i:nums) printf("%d, ",i);
        printf("\n");
        
        printf("queries[]=");
        for(auto &i:queries) printf("%d, ",i);
        printf("\n");
        
        printf("presum and sorting done\n");
        */
        for(int i = 0; i<m;i++) {
            int q = queries[i];
            int j = 0;
            for(j=0;j<n;j++) {
                if(nums[j]>q) {
                    //printf("j=%d",j);
                    break;
                }
            }
            ans[i]=j;
            //printf("ans[i=%d]=%d\n",i,j);
        }
        return ans;
    }
    
};