class Solution {
    //https://leetcode.com/problems/excel-sheet-column-title
public:
    /*
        Observation
         A -> 1
         Z -> 26
        AA -> 26+1
        AB -> 26+2
        AZ -> 26+26
        BA -> 2*26+1
        ZA -> 26*26+1
        ZZ -> 26*26+26 -> like Z*26^1 + Z*26^0 
       AAA -> 26*26 + 26 + 1 
       ABA -> 26*26 + 2*26+1
       AZZ -> 26*26 + 26*26 + 26 -> like A*26^2 + Z*26^1 + Z*26^0
       BAA -> 2*26*26 +26 + 1   --> like B*26^2 + A*26^1 + A*26^0
       
       BA A-> 26*(B*26 + A) + A = B*26^2 + A*26 + A
       So, BA A = 26*(BA) + A
       if n%26 > 0, then sequence = 26*(n/26) + n%26
       if n%26== 0, then mean n is 26? -> Z... sequence = 26*((n-26)/26) + 26
       
    */
    string convertToTitle(int columnNumber) {
        //vector<int> v = vector<int>(256,0);
        vector<char> u = vector<char>(27,0); 
        //for(char c='A';c<='Z';c++) v[c]=c-'A'+1;
        for(int i=1;i<=26;i++) u[i]='A'+i-1;
        string ans = "";
        int i = columnNumber;
        while(i>0) {
            if(i%26>0) {
                //printf("[case i%26>0] push u[i%26]=%c (ASC=%d),when i%26==%d\n",u[i%26],u[i%26],i%26);
                ans.push_back(u[i%26]);
                i/=26;
            } else {//i%26==0
                //printf("[case i%26==0] push u[26]=%c (ASC=%d)\n",u[26],u[26]);
                ans.push_back(u[26]);
                i = (i-26)/26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};