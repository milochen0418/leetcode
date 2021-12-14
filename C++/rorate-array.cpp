//https://leetcode.com/problems/rotate-array/
//189. Rotate Array
class Solution {
public:
    
    //[0,1,2,3,4,5,6] steps 3
    //0,3,6,2,5,1,4,0
    
    //[0,1,2,3,4,5,6,7] steps 4
    //0,4,0
    //1,5,1
    //2,6,2
    //3,7,3
    
    //[0,1,2,3,4,5,6,7] steps 2
    //0,2,4,6,0
    //1,3,5,7,1
 
    //[0,1,2,3,4,5,6,7,8,9,10,11] step 3  
    //0,3,6,9,0
    //1,4,7,10,1
    //2,5,8,11,2

    /* 
      if (nums.size() % k == 0 ) {
        for(i = 0; i < k; i++) {
          for(j = 0 ; j < nums.size() / k; j++) {
            //process rotate 
          }
        }
      }
    */
    /*
      if (nums.size() % k != 0) {

      }
    */

    // missed test case is here
    //[0,1,2,3,4,5] step 4
    //0,4,2,0
    //1,5,3,1
    // So change to use gcd()
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int rows = gcd(n, k);
        for(int i = 0; i < rows; i++) {
            int temp = nums[i];
            int curr_idx = i;                
            for(int j = 0 ; j < n / rows; j++) {
                int next_idx = (curr_idx + k) % n;
                int prev_temp = temp;
                temp = nums[next_idx];
                nums[next_idx] = prev_temp;
                curr_idx = next_idx;
            }
        }   
    }

};