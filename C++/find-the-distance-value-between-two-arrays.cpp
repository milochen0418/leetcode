class Solution {
    //https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
public:
    bool isValid(vector<int>&arr,int target,int d){
        
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            
            int mid = low + (high - low)/2;
            if(abs(arr[mid] - target) <= d){
                return false;
            }
            else if(arr[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        return true;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(),arr2.end());
        
        int cnt = 0;
        for(auto num:arr1){
           if(isValid(arr2,num,d)){
               cnt++;
           } 
        }
        
        return cnt;
    }
};