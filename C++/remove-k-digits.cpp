class Solution {
    // https://leetcode.com/problems/remove-k-digits/
public:
    string removeKdigits(string num, int k) {
        for(int i = 0; i<k;i++) {
            int n = num.size();
            for(int j = 0; j<n;j++) {
               if(j+1>=n || num[j+1]<num[j]) {
                   num.erase(j,1);
                   break;
               } 
            }
            if(num.size() > 1 && num[0]=='0') {
                //process testcase of "10200" 3
                num.erase(0,1);
            }
        }      
        if(num=="") return "0";
        return num;
    }
};

/* testcase
"1432219"
3
"10200"
3
"10"
2
"10001"
1
*/