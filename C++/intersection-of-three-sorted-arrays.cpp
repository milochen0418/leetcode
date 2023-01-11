class Solution {
    //https://leetcode.com/problems/intersection-of-three-sorted-arrays
public:
    vector<int> ans;
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> A = intersection(arr1, arr2);
        vector<int> ans = intersection(A, arr3);
        return ans;
    }
    vector<int> intersection(vector<int>& A, vector<int>& B){
        vector<int> ans;
        int i=0,j=0;
        while(i<A.size() || j<B.size()) 
            if(i<A.size() && j<B.size())
                if(A[i]==B[j]) 
                    ans.push_back(A[i++]=B[j++]);
                else 
                    A[i]<B[j]?i++:j++;            
            else 
                i>A.size()?j++:i++;
        return ans;
    }

    vector<int> intersection_v01(vector<int>& A, vector<int>& B){
        vector<int> ans;
        int i=0,j=0;
        while(i<A.size() || j<B.size()) {
            if(i<A.size() && j<B.size()) {
                if(A[i]==B[j]) {
                    ans.push_back(A[i]);
                    i++,j++;
                } else {
                    A[i]<B[j]?i++:j++;
                }                
            } else {
                i>A.size()?j++:i++;
            }
        }
        return ans;
    }
    vector<int> intersection_v01(vector<int>& A, vector<int>& B){
        vector<int> ans = {};
        int i=0,j=0;
        while(i<A.size() || j<B.size()) {
            if(i>=A.size()) {
                j++;
            } else if(j>=B.size()){
                i++;
            } else if(A[i]==B[j]) {
                ans.push_back(A[i]);
                i++,j++;
            } else if(A[i]<=B[j]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};