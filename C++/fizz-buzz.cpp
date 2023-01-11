class Solution {
    //https://leetcode.com/problems/fizz-buzz
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans=vector<string>(n,"");
        for(int i = 0;i<n;i++) {
            int idx = i+1;
            auto &str = ans[i];
            if(idx%3==0) str.append("Fizz");
            if(idx%5==0) str.append("Buzz");
            if(idx%5!=0 && idx%3!=0) str = to_string(idx);
        }
        return ans;      
    }
};