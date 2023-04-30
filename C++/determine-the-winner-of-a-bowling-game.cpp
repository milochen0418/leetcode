class Solution {
    //https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int sum1 = 0, sum2=0;
        
        for(int i = 0;i<n;i++) {
            sum1+=player1[i];
            if( (i-1>=0 && player1[i-1]>=10) || (i-2>=0 && player1[i-2]>=10) )  sum1+=player1[i];
        }
        
        for(int i = 0;i<n;i++) {
            sum2+=player2[i];
            if( (i-1>=0 && player2[i-1]>=10) || (i-2>=0 && player2[i-2]>=10) )  sum2+=player2[i];
        }
        //printf("sum1=%d, sum2=%d\n",sum1,sum2);
        if(sum1==sum2) return 0;
        if(sum1>sum2) 
            return 1;
        else 
            return  2;    
    }
};