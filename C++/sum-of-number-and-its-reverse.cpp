class Solution {
    //https://leetcode.com/problems/sum-of-number-and-its-reverse/
public:
    /*
    for all 0<=i<=n-1, 0<=a_i && ai_i<=9
     n/2
    Sigma ( a_n-k + a_i ) * 10^i
     i=0
     
     3
    */
    bool sumOfNumberAndReverse(int num) {
        string num_s = to_string(num);
        //string num_s_reverse = reverse(num_s);
        
        
            
        int n = num_s.length();
        if(num_s[0] !='1') {
            for(int i = 0; i < n; i++) {
                int a = num_s[n-1-i]-'0';
                int b = num_s[i]-'0';
                if(abs(a-b)>1) {
                    printf("No Answer by early judge\n");
                    return false;
                }
            }   
        }
        
        //return true;
        
        
        for(int i = 0; i<=100000/2;i++) {
            string s = to_string(i);
            reverse(s.begin(), s.end());
            int reverse = atoi(s.c_str());
            if(reverse + i == num) {
                printf("Get Answer i=%d, reverse = %d\n", i, reverse);
                return true;
            }
        }
        printf("No Answer after bruteforce\n");
        return false;
        
    }
};