class Solution {
public:
    
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd;
        vector<int> even;
        vector<int> result(n);
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }
        sort(odd.begin(), odd.end());//odd=1234
        reverse(odd.begin(), odd.end()); //odd=4321
        sort(even.begin(), even.end()); //even=1234
        /*
Input: nums = [4,1,2,3]
Output: [2,3,4,1]
Explanation: 
First, we sort the values present at odd indices (1 and 3) in non-increasing order.
So, nums changes from [4,1,2,3] to [4,3,2,1].
Next, we sort the values present at even indices (0 and 2) in non-decreasing order.
So, nums changes from [4,1,2,3] to [2,3,4,1].
Thus, the array formed after rearranging the values is [2,3,4,1].        

        odd =     4 3 2 1
        even =    1 2 3 4
        result = [1 3 3 1]
        */
        //return even;
        
        int even_i =0;
        int odd_i = 0;
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                result[i] = even[even_i++];
            } else {
                result[i] = odd[odd_i++];
            }
        }
        return result;
    }
};