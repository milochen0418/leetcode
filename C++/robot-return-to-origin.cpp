class Solution {
    //https://leetcode.com/problems/robot-return-to-origin
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        vector<function<void()>> f = vector<function<void()>>(256,0);
        f['L']=[&](){x--;};
        f['R']=[&](){x++;};
        f['U']=[&](){y--;};
        f['D']=[&](){y++;};
        for(auto &c:moves) f[c]();
        return x==0 && y==0;
    }
};