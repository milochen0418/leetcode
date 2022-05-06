class Solution {
    //https://leetcode.com/problems/find-permutation/
public:
    vector<int> findPermutation(string s) {
        return vector<int>();
        /*
        I [1,2]
        DI [2,1,3]
        DDI [3,2,1,4]
        DDII [3,2,1,4,5]
        DDIID [3,2,1,4,6,5]
        DDIIDD [3,2,1,4,7,6,5]
        DDIDD [3,2,1,6,5,4]
        DDIDDDIDDDDI [3,2,1,7,6,5,4,12,11,10,9,8,13]
        DDIDDDIDDDDII [3,2,1,7,6,5,4,12,11,10,9,8,13,14]
        DDIDDDIDDDDIII [3,2,1,7,6,5,4,12,11,10,9,8,13,14,15]
        DDIDDDIDDDDIIIDD [3,2,1,7,6,5,4,12,11,10,9,8,13,14,17,16,15]
        */
        //The key point is to process How many IDD...D 
    }
};