class Solution {
    //https://leetcode.com/problems/armstrong-number
public:
    bool isArmstrong(int n) {
        int input = n;
        //1*1*1*1 + 6*6*6*6 + 3*3*3*3 + 4*4*4*4 = 1634
        int ans=0, m=0;//the number of digits
        
        vector<int> v;
        while(n>0) {
            v.push_back(n%10);
            n/=10;
            m++;
        }
        int sum = 0; 
        for(auto &i:v){
            int p = 1;
            for(int j = 0;j<m;j++) p=p*i;
            sum+=p;
        }
        //printf("sum = %d\n",sum);
        return sum == input;            
        
    }
};