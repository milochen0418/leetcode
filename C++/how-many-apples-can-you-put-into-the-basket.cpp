class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int ans=0;
        int total = 0;
        for(auto &w: weight) {
            if(total+w <= 5000) {
                ans++;
                total+=w;
            } else {
                break;
            }
        }
        return ans;
    }
};