class Solution {
    //https://leetcode.com/problems/valid-mountain-array
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int candidate_idx = -1;
        for(int i=1; i<arr.size()-1;i++) { 
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                candidate_idx = i;
                break;
            }
        }
        if(candidate_idx == -1) return false;
        
        for(int i =0; i < candidate_idx; i++) {
            if (!(arr[i] < arr[i+1])) return false;
        }
        for(int i = candidate_idx; i<arr.size()-1;i++) {
            if(!(arr[i] > arr[i+1])) return false;
        }
        return true;
    }
};