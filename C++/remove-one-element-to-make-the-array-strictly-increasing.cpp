class Solution {
    //https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
    //article https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/discuss/2916742/C%2B%2B-or-O(N)-or-easy
public:
    bool canBeIncreasing(vector<int>& nums) {
        if(removeOne(nums)==false) return true;
        if(removeOne(nums)==true) return false;
        return true;
    }
    
    bool removeOne(vector<int>& A) {
        for(int i = 1; i<A.size();i++) {
            if(!(A[i-1]<A[i])) {
                int L = i-2>=0?A[i-2]:INT_MIN;
                int R = i+1<A.size()?A[i+1]:INT_MAX;
                if(L<A[i-1]&&A[i-1]<R) 
                    A.erase(A.begin() + i);    
                else 
                    A.erase(A.begin() + (i-1));
                return true;
            }            
        }
        return false;
    }
};