class Solution {
    //https://leetcode.com/problems/count-symmetric-integers
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i<=high;i++) {
            string str = to_string(i);
            int n = str.length();
            if(n %2 != 0) continue;
            int sum1 = 0, sum2=0;
            for(int j = 0; j<n/2;j++) sum1+=str[j]-'0';
            for(int j = n/2; j<n;j++) sum2+=str[j]-'0';
            if(sum1==sum2)  ans++;
        }
        return ans;
    }
};