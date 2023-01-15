class Solution {
    //https://leetcode.com/problems/simplified-fractions
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i = 1; i<=n;i++)
            for(int j = i+1;j<=n;j++) 
                if(gcd(i,j)==1)     
                    ans.push_back(to_string(i)+"/"+to_string(j));
        return ans;
    }
};