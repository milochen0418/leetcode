class Solution {
    //https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
public:
    int punishmentNumber(int n) {
        int ans = 0;
        
        printf("puns = ");
        for(int i = 0; i<=n;i++) {
            if(is_pun(i)) {
                printf("%d, ", i);
                ans+= i*i;
            }
        }
        printf("\n");
        
        //for(int i = 1;i<=10;i++)is_pun(i);
        //is_pun(9);
        return ans;
    }
    int is_pun(int v) {
        /*
        Is 1000 punishment number? YES
        1000*1000 = 1,000,000
        2^6-1 = 64-1 = 63
        1|0|0|0|0|0|0
        
        所有可能的 "combination" 找到後，試著爆力解
        1 0 0 0 0 0 0 
         0 0 0 0 0 0
         
        1 0 0 0 0 0|0
         0 0 0 0 0 1
         
        1 0 0 0 0|0 0
         0 0 0 0 1 0
         
        1 0 0 0 0|0|0
         0 0 0 0 1 1
         
        1 0 0 0|0 0 0
         0 0 0 1 0 0 
         
        1 0 0 0|0 0|0
         0 0 0 1 0 1 
         
        000000  0 
        000001
        000010
        000011
        000100
        ...
        111110
        111111   2^6 - 1
        
        for (mask = 1 to m)   ... m 最大為 2^6-1 = 63
        
        1|0|0|0|0|0|0
        
        */
        
        int square = v*v;
        string square_s = to_string(square);
        int len = square_s.length();
        int m = (1<<(len-1))-1;
        
        //printf("v=%d, square = %d, m=%d\n",v,square, m);
        
        int flag = 0;
        for(int mask = 0; mask<=m;mask++) {
            string s = square_s;
            int n = (int)s.length();
            int sum = 0;
            string tmp = "";
            for(int i = 0; i<n;i++) {      //  s = "1 0|0 0 0|0 0"       
                                           //mask= " 0 1 0 0 1 0"
                tmp.push_back(s[i]);
                //printf("i=%d",i);
                if(i==n-1 ||  (mask&(1<<i))>0 ) {
                    int val = stoi(tmp);
                    tmp = "";
                    sum+=val;
                    //printf("mask = %d, val=%d,curr sum = %d\n",mask,val,sum);
                } 
            }
            //if(sum == square) {
            if(sum == v) {
                //printf("mask = %d, sum=%d, v=%d, square=%d ->", mask,sum,v,square);
                flag = 1;
                break;
            }
        }
        //if(flag==1) printf("pun = %d\n", v);
        return flag;
    }
};