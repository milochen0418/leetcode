class Solution {
    //https://leetcode.com/problems/sort-array-by-parity/
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int i=0,j=a.size()-1;
        while(i<j) {
            if (a[i]%2==0) { 
                i++;
            } else if(a[j]%2!=0) {
                j--;
            } else {
                swap(a[i],a[j]);
            }
        }
        return a;
    }
};