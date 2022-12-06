class Solution {
    //https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter
public:
    int minTimeToType(string word) {
        /*
        dis = abs(letter_a -letter_b)
        dis = min(dis,26-dis);
        */
        int ans = word.size(), dis=0,n = word.size();
        for(int i = 0;i<n;i++) {
            char word_i_1=i==0?'a':word[i-1];
            dis = abs(word[i]-word_i_1);
            ans += min(dis, 26-dis);
        }
        return ans;
    }
};