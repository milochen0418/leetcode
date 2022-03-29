class Solution {
    //https://leetcode.com/problems/sort-array-by-parity/
    //article https://leetcode.com/problems/sort-array-by-parity/discuss/1893555/C%2B%2B-or-two-pointers-approach-or-time-O(n)-space-O(1)
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