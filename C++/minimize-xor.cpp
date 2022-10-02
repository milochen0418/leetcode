class Solution {
    //https://leetcode.com/problems/minimize-xor/
public:
    int minimizeXor(int num1, int num2) {
        int n1= num1;
        int n2= num2;
        int cnt2 =0 ;//number of bit 1 in nums2
        while(num2>0) {
            cnt2 = cnt2 + num2%2;
            num2=num2/2;
        }
        
        int cnt1 =0 ;//number of bit 1 in nums1
        while(num1>0) {
            cnt1 = cnt1 + num1%2;
            num1=num1/2;
        }
        num1 = n1;
        num2 = n2;
        if(cnt2 == cnt1) return num1;
        /*
           num1 = 11001010  cnt1 = 4    cnt2 = 2
              x = 00001010
        case cnt1 > cnt2: We want x XOR num1 minimal 
            Answer is largest possible of #cnt2 1 in cnt1
            for examaple, cnt2=3 and num1 = 11010011 -> ans = 11010000
            num1= 11010011 = 1+2+16+64+128 = 211
            ans = 11010000 = 208
            num2= 7
            cnt1-cnt2 = 2
            11010011
            110100
            11010000 -> ans
            
        case cnt2 > cnt1:
            for example, cnt2=6 and 
               num2 = 00111111 = 1+2+4+8+16+32 = 63
               num1 = 10011001 = 1+8+16+128 = 153
            Answer is 10011111 = 1+2+4+8+16+128 = 159
            
            cnt = cnt2-cnt1 = 6-4 = 2
            10011001
            1001100 cnt=2
            100110 cnt=1 
            10011 cnt=0
            
            10011111
            
        */
        
        
        if(cnt1>cnt2) {
            //kill cnt1-cnt2 minimal 1  in num1
            int cnt = cnt1-cnt2;
            int bcnt = 0;
            int ans = num1;
            while(cnt>0) {
                //printf("ans=%d\n",ans);
                int r = ans % 2;
                ans = ans / 2;
                if(r==1) cnt--; 
                bcnt++;
            }
            ans = ans<< bcnt;
            return ans;
        } else {
            //case cnt2>cnt1 
            int cnt = cnt2 - cnt1;
            int bcnt = 0; 
            int ans = num1;
            while(cnt>0) {
                int r = ans %2;
                ans = ans/ 2;
                if(r==0) cnt--;
                bcnt++;
            } 
            for(int i = 0; i<bcnt;i++) {
                ans = ans*2+1;
            }
            return ans;
        }
    }
};