class Solution {
    //https://leetcode.com/problems/flipping-an-image/
public:
    vector<vector<int>>& flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &v:image) reverse(v.begin(), v.end());
        for(auto &v:image) for(auto &i:v) i=(i==0);
        return image;
    }
};