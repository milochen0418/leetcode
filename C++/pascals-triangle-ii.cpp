class Solution {
    //https://leetcode.com/problems/pascals-triangle-ii
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a=vector<int>(rowIndex+1,1);
        if(rowIndex<=1) return a;
        for(int i = 2;i<=rowIndex;i++) {
            int l = a[0];
            int r = a[1];
            for(int j = 1;j<i;j++) {
                a[j] = l+r;
                l=r;
                r=a[j+1];
            }
        }
        return a;
    }
};