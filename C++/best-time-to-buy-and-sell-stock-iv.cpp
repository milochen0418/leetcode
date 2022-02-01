class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
public:
/*
2
[3,2,6,5,0,3]
1
[1,2]
2
[2,4,1]
*/
    
    int maxProfit(int k, vector<int>& prices) {
        vector<int>& p = prices;
        int n = p.size();
        //m M m M m M
        //(mM)(mM)(mM)
        //(mMmM)(mM)
        //When #(mM) is not enough, then use connect 2 (mM) as one 
        //first m from [0..i] 
        //last M is in [k..n-1]
        vector<int> m;
        vector<int> M;
        
        bool is_falling =true;
        for(int i = 0; i < n; i++) {
            if(is_falling==true) {
                if(i+1<n && p[i+1]>p[i]) {
                    m.push_back(i);
                    is_falling = false;
                }        
            } else {
                if( i+1>=n || p[i+1]<p[i]) {
                    M.push_back(i);
                    is_falling = true;                    
                }
            }
        }
        int sum = 0;
        n = M.size();
        
        for(int i=0;i<n;i++) {
            sum += (p[M[i]] - p[m[i]]);
        }        
        return sum;
    }
};