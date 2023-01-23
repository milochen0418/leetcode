class Solution {
    //https://leetcode.com/problems/confusing-number-ii
    //article https://leetcode.com/problems/confusing-number-ii/discuss/3088589/C%2B%2B-Iterative-super-easy-25-lines
public:
    int confusingNumberII(int n) {
        //Because some digit is invalid, so 
        //Genearte all number with 0, 1, 6, 8, and 9
        const vector<int> d={0,1,6,8,9};
        int m = 5*5*5*5*5*5*5*5*5;
        vector<int> num = vector<int>(10,0);
        int ans = 0;
        for(int i = 0;i<m;i++) {
            int j=0; //countup one in num for base-5 format
            while(++num[j]==5) num[j++]=0;
            int val=0;//get val from num in base-10 format
            for(int i =num.size()-1;i>=0;i--)
                val=val*10+d[num[i]];
            if(val>n) break;//stop when val is larger than n
            ans+=is_confusing_number(val);
        }
        return ans;
    }


    int confusingNumberII_TLE(int n) {
        int ans=0;
        for(int i = 1;i<=n;i++) ans+=is_confusing_number(i);
        return ans;
    }
    const vector<int> mp={0, 1,-1,-1,-1,-1, 9,-1, 8, 6};
    int is_confusing_number(int n) {
        int v=n,m=0;
        while(v>0) {
            if(mp[v%10]==-1) return 0;
            m = m*10 + mp[v%10];
            v/=10;
        }
        return n!=m;
    }  
};