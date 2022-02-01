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
2
[3,3,5,0,0,3,1,4]
1
[6,1,6,4,3,0,2]
2
[]
1
[1]
2
[1,2,4,2,5,7,2,4,9,0,9]
*/     
    int maxProfit(int k, vector<int>& prices) {
        vector<int>& p = prices;
        int n = p.size();
        if(n<=1) return 0;
        
        //m M m M m M
        //(mM)(mM)(mM)
        //(mMmM)(mM)
        //When #(mM) is not enough, then use connect 2 (mM) as one 
        //first m from [0..i] 
        //last M is in [k..n-1]
        vector<int> m,M;
        vector<pair<int, pair<int,int> >> P; //each element is  { profit_value, {m_Idx, M_idx} } 
        
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
        n = M.size();
        priority_queue<int, vector<int>, greater<int>> minDQ;
        priority_queue<int> maxDQ;
        priority_queue<int, vector<int>, greater<int>> minUQ;
        priority_queue<int> maxUQ;
        
        if(n==0)return 0;
        for(int i=0;i<n;i++) {
            P.push_back( {p[M[i]] - p[m[i]], {m[i], M[i]} });
            minUQ.push(p[M[i]] - p[m[i]]);
            maxUQ.push(p[M[i]] - p[m[i]]);
        }
        
        
        //vector<int> D(P.size()-1);
        vector<int> D;
        for(int i=0;i<P.size()-1;i++) {
            D.push_back( p[P[i].second.second] - p[P[i+1].second.first]);
            minDQ.push(p[P[i].second.second] - p[P[i+1].second.first]);
            maxDQ.push(p[P[i].second.second] - p[P[i+1].second.first]);
        }
        int sum = 0;
        int sum_upper_bound = accumulate(P.begin(), P.end(),0,[](int s, auto e){return s+e.first;});
        int sum_lower_bound = p[P[0].second.second] - p[P[n-1].second.first];
        
        //return sum_lower_bound;
        //return P.size();
        //return P[0].first*100 + P[1].first*10 + P[2].first;
        //return D[1]*10 + D[0];
        //if(k>=D.size()) return sum_upper_bound;
        if(k>=P.size()) return sum_upper_bound;
        /*
        sum = sum_lower_bound;
        while(k>0) {
            sum += maxQ.top();
            maxQ.pop();
            k--;
        }
        return sum;
        */
        sum = sum_upper_bound;
        
        for(int i=0; i<P.size()-k;i++) {
            if(minUQ.top()<minDQ.top()) {
                sum -= minUQ.top();
                minUQ.pop();                
            } else {
                sum -= minDQ.top();
                minDQ.pop();                
                
            }
        }
        return sum;
        //return sum_upper_bound-minDQ.top();
        
    }
};