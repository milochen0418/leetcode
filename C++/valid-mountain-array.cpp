class Solution {
    //https://leetcode.com/problems/valid-mountain-array
public:
    bool validMountainArray(vector<int>& arr) {        
        if(arr.size() < 3) return false;
        if(!(arr[0] < arr[1])) return false;
        if(!(arr[arr.size()-2] > arr[arr.size()-1])) return false;
        int candidate_idx = -1;
        bool mountain_arrived = false;
        for(int i =1; i<arr.size()-1; i++) {
            if(!mountain_arrived) {
                if(!(arr[i] < arr[i+1])) {
                    if(arr[i] == arr[i+1]) { 
                        return false;
                    } else {
                        mountain_arrived = true;              
                    }
                }
            } else {
                if(!(arr[i] > arr[i+1])) return false;
            }
        }
        return true;
    }
};