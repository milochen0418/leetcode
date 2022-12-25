class Solution {
    //https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string
public:
    int minOperations(string s) {
        
        //Because the final result will be one of these string
        //10101010...  
        //01010101... 
        //So we just need to compare for this
        int ans0=0, ans1=0, n = s.length(); //start from 0 ->ans0 , start from 1 -> ans1
        for(int i = 0;i<n;i++) 
            if(i%2==0) 
                (s[i]=='1'?ans0:ans1)++;
            else 
                (s[i]=='0'?ans0:ans1)++;
        return min(ans0,ans1);
        
    }
};