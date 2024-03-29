class Solution {
    //https://leetcode.com/problems/remove-element/
    //article https://leetcode.com/problems/remove-element/discuss/1894691/C%2B%2B-or-two-pointer-approach
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0, n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] != val) {
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }

    int removeElement_v03(vector<int>& nums, int val) {
        int cnt = 0, n = nums.size();
        for(int i = 0; i<n; i++) {
            nums[i-cnt] = nums[i];
            if(nums[i] == val) cnt++;
        }
        return n-cnt;
    }

    int removeElement_v02(vector<int>& nums, int val) {
        int n = nums.size();
        if (n==0) return 0;
        int i = 0, j = n-1;
        while(i<j) {
            if(nums[j]==val) j--;
            else if(nums[i]!=val) i++;
            else swap(nums[i],nums[j]);
        }
        while(j<n && nums[j]!=val) j++;
        return j;
    }
    int answer1(vector<int>& nums, int val) {
        int i = 0;
        int k = nums.size();
        while (i < k) {
            if(nums[i] == val) {
                nums[i] = nums[k-1];
                k--;
            } else {
                i++;
            }
        }
        return k;
    }

};