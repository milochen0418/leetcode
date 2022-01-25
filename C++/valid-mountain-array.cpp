class Solution {
    //https://leetcode.com/problems/valid-mountain-array
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        bool mountain_arrived = false;
        for (int i = 0 ; i < arr.size()-1; i++)             
            if (mountain_arrived) 
                if (!(arr[i] > arr[i+1])) return false; else continue;
            else if (!(arr[i] < arr[i+1])) 
                if (i==0 || arr[i] == arr[i+1]) 
                    return false;
                else 
                    mountain_arrived = (i!=arr.size()-2 || arr[arr.size()-1] < arr[arr.size()-2]);                
        return mountain_arrived;
    }
};