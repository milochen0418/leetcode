class Solution {
    //https://leetcode.com/problems/longest-nice-subarray/
    //https://leetcode.com/problems/longest-nice-subarray/discuss/2528081/C%2B%2B-or-two-pointer
    /*
    max_cnt alwasy largest (R-L+1) 
    [1,3,8,48,10]
      0000 0001    1   ALLAND = 0000 0001
      0000 0011    3   ALLAND = 0000 0011
      0000 1000    8   ALLAND = 0000 1011
 L    0011 0000    48  ALLAND = 0011 1011 
   R  0000 1010    10  ALLAND = 0011 1010
   
   R-L+1 = 2  answer 
   
   ALLAND = 0011 1011 -> 0011 1000  -> 0011 0000 -> 0011 1010 
   
   
    */
    
public:
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {        
        int L = 0, R=0, cur=0, ans=0, n = nums.size();
        while(L<n && R < n) {   
            if(L>R) //always keep L in left of R
                R=L;
            else if((cur&nums[R]) == 0) //if it is disjoint 
                cur = cur | nums[R++]; //add related bit 1 from nums[R]
            else //if it is not disjoint
                cur = cur & (~nums[L++]); //delete related bit 1 from nums[L]
            ans = max(ans, R-L);
        }
        return ans;
    }
};

    int longestNiceSubarray_v01(vector<int>& nums) {
        //printf("\nlongestNiceSubarray\n");
        int max_cnt = 1;
        int n = nums.size();
        int L = 0, R = 0;
        int ALLAND =0;
        while(L<n && R<n) {
            if(L==R) {
                ALLAND = nums[L];
                max_cnt = max(max_cnt, R-L+1);
                //printf("L=%d, R=%d, R-L+1=%d, ALLAND=%d, max_cnt=%d, \n", L,R,R-L+1, ALLAND, max_cnt);
                R++;
            } else {
                if( (ALLAND & nums[R]) == 0) {
                    ALLAND = (ALLAND | nums[R]);
                    max_cnt = max(max_cnt, R-L+1);
                    //printf("L=%d, R=%d, R-L+1=%d, ALLAND=%d, max_cnt=%d, \n", L,R,R-L+1, ALLAND, max_cnt);
                    R++;
                } else {
                    while(L<R) {
                        ALLAND = (ALLAND & (~(nums[L]) ));
                        L++;
                        if( (nums[L] & nums[R]) == 0 ) {
                            break;
                        }
                    }
                }
            }
        }
        return max_cnt;
    }
};