class Solution {
    //https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
public:
    int maxVowels(string s, int k) {
        vector<int> v=vector<int>(256,0);
        v['a']=v['e']=v['i']=v['o']=v['u']=1;
        int num = 0, n = s.length(); 
        for(int i = 0;i<k;i++) num+=v[s[i]];
        int ans = num;
        for(int i=k;i<n;i++) {
            num+=v[s[i]];
            num-=v[s[i-k]];
            ans = max(ans, num);
        }
        return ans;
    }
};