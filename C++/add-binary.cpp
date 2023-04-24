class Solution {
    //https://leetcode.com/problems/add-binary
public:
    string addBinary(string a, string b) {
        int i = (int)A.length()-1, j=(int)B.length()-1, C=0;
        string ans;
        while(i>=0 || j>=0 || C>0) {
            if(i>=0) C+=A[i--]-'0';
            if(j>=0) C+=B[j--]-'0';
            ans.push_back((C%2)+'0');
            C/=2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string addBinary_Ver02(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.length()<b.length()) swap(a,b);
        //a.length() >= b.length() now.
        int m = a.length(), n = b.length();
        int C = 0, S=0;
        for(int i=0; i<m; i++) {
            int A = a[i]-'0', B=i<n?b[i]-'0':0;
            S = (A+B+C);
            C = S/2;
            a[i] = (S%2) + '0';
        }
        if(C>0)a.push_back(C+'0');
        reverse(a.begin(), a.end());
        return a;
    }


    string addBinary_Ver01(string a, string b) {
        string ans="";
        int m = a.length(), n = b.length(), end = max(m,n);
        int bit_c = 0;
        for(int i = 0; i<end;i++) {
            int bit_a = m-i-1>=0?a[m-i-1]-'0':0;
            int bit_b = n-i-1>=0?b[n-i-1]-'0':0;
            int sum = bit_a+bit_b+bit_c;
            bit_c = sum/2;
            sum = sum%2;
            ans.push_back(sum+'0');
        }
        if(bit_c>0)ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};