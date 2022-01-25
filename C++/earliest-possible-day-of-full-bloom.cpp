class Solution {
    //https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> data(n);
        for(int i=0;i<n;i++) {
            data[i] = {plantTime[i], growTime[i]};
        }
        sort(data.begin(), data.end(), 
             []( const auto& p1 , const auto& p2 ){
                auto[pt1,gt1] = p1;
                auto[pt2,gt2] = p2;
                if(gt1 != gt2) return gt1 > gt2;
                return pt1+gt1 > pt2 + gt2;
            });
        int res = 0;
        int cur = 0;
        for (const auto&p: data) {
            auto[pt,gt]=p;
            res = max(res, cur + pt + gt);
            cur += pt;
        }
        return res;
    }
};