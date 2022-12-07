class Solution {
    //https://leetcode.com/problems/finding-3-digit-even-numbers
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        /*
        digit0 | digit1 | digit2 is the following
        [1,2,3,4,5,6,7,8,9] | [0,1,2,3,4,5,6,7,8,9] | [2,4,6,8,0]
        */
        vector<int> vc0 = {1,2,3,4,5,6,7,8,9};
        vector<int> vc1 = {0,1,2,3,4,5,6,7,8,9};
        vector<int> vc2 = {0,2,4,6,8};
        vector<int> vcnt = vector<int>(10,0), ans;
        for(auto &d: digits) vcnt[d]++;
        vector<int> tmp  = vcnt;
        for(auto&d2: vc2) {
            tmp[d2]--;
            if(tmp[d2]>=0) for(auto&d0: vc0){
                tmp[d0]--;
                if(tmp[d0]>=0) for (auto &d1:vc1) {
                    tmp[d1]--;
                    if(tmp[d1]>=0) ans.push_back(d0*100+d1*10+d2);
                    tmp[d1]++;
                }
                tmp[d0]++;
            }
            tmp[d2]++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};