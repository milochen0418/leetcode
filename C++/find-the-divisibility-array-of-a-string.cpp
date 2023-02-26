class Solution {
    //https://leetcode.com/problems/find-the-divisibility-array-of-a-string
public:
    typedef long long ll ;
    vector<int> divisibilityArray(string word, int mm) {
        ll m = mm;
        int n = word.length();
        /*
        "9 9 8 2 4 4 3 5 3"
        [1,1,0,0,0,1,1,0,0] <-- Expected Answer
        r=0;
        r*10 + 9 =  9 -> r = 0 -> ans[0] = 1
        r*10 + 9 =  9 -> r = 0 -> ans[1] = 1
        r*10 + 8 =  8 -> r = 2 -> ans[2] = 0
        r*10 + 2 = 22 -> r = 1 -> ans[3] = 0
        r*10 + 4 = 14 -> r = 2 -> ans[4] = 0
        r*10 + 4 = 24 -> r = 0 -> ans[5] = 1
        r*10 + 3 =  3 -> r = 0 -> ans[6] = 1
        r*10 + 5 =  5 -> r = 2 -> ans[7] = 0
        r*10 + 3 =  5 -> r = 0 -> ans[8] = 1
        */
        ll r = 0;
        vector<int> ans;
        for(int i = 0; i<n;i++) {
            r = r*10 + (ll)(word[i] - '0');
            r = r % m;
            ans.push_back(r==0?1:0);
        }
        return ans;
    }
};