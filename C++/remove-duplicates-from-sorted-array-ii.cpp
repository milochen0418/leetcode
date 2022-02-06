class Solution {
    //https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
    //article https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/1749738/C%2B%2B-or-step-by-step-from-idea
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5044285435593907/
public:
    int removeDuplicates(vector<int>& vs) {
        int i = 0;
        for (auto& v: vs)  if ( i < 2 || v != vs[i-2] ) vs[i++] = v;
        return i;
    }
};