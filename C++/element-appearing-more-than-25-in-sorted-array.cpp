class Solution {
    //https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int k = n/4;
        int cnt = 1;
        for(int i = 1;i<n;i++) {
            cnt = arr[i-1] == arr[i]?cnt+1:1;
            if(cnt>k) return arr[i];            
        }
        return arr[0]; //process the case for if only one element in arr
    }
};