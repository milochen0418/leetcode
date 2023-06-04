class Solution {
public:
    typedef long long ll;    
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        ll ans = 0;
        ll maxv = (ll)n*(ll)n;
        ll cnt = 0;
        vector<int> cols_changed = vector<int>(n,0);
        vector<int> rows_changed = vector<int>(n,0);
        unordered_set<int> rows_unchanged = unordered_set<int>();
        unordered_set<int> cols_unchanged = unordered_set<int>();
        
        for(int i = 0;i<n;i++) {
            rows_unchanged.insert(i);
            cols_unchanged.insert(i);
        }
        
        int m = queries.size();
        for(int i = m-1 ; i>=0; i--) {
            vector<int> &q = queries[i];
            int type=q[0], idx=q[1], val=q[2];
            
            if(type == 0 && cols_changed[idx] == 0) {//change columns
                cols_changed[idx] = 1;
                cols_unchanged.erase(idx);
                cnt+=rows_unchanged.size();
                ans+=val*rows_unchanged.size();
            } else if(type == 1 && rows_changed[idx] == 0){//change rows
                rows_changed[idx] = 1;
                rows_unchanged.erase(idx);
                cnt+=cols_unchanged.size();
                ans+=val*cols_unchanged.size();                           
            }
            if(cnt>=maxv) break;
        }        
        return ans;
    }

    long long matrixSumQueries_v01(int n, vector<vector<int>>& queries) {
        vector<vector<ll>> A = vector<vector<ll>>(n, vector<ll>(n,0));
        for(auto &q:queries) {
            int idx = q[1], val = q[2];
            if(q[0] == 0) //change column
                for(int i = 0;i<n;i++) 
                    A[i][idx] = val;
            else //change row
                for(int i = 0;i<n;i++) 
                    A[idx][i] = val;
        }
        ll ans = 0;
        for(int i = 0; i<n;i++)
            for(int j =0;j<n;j++)
               ans = ans + A[i][j]; 
        return ans;
    }  
    
    long long matrixSumQueries_v02(int n, vector<vector<int>>& queries) {
        vector<int> cvals = vector<int>(n,0);
        vector<int> rvals = vector<int>(n,0);
        vector<unordered_set<int>> csets = vector<unordered_set<int>>(n, unordered_set<int>());
        vector<unordered_set<int>> rsets = vector<unordered_set<int>>(n, unordered_set<int>());
        
        for(auto &q: queries) {
            int type = q[0], idx = q[1],val = q[2];
            if(type==0) {//change column
                cvals[idx] = val;
                csets[idx] = unordered_set<int>();
                for(int i = 0;i<n;i++)
                    rsets[i].insert(idx);
            } else {//change row
                rvals[idx] = val;
                rsets[idx] = unordered_set<int>();
                for(int i = 0;i<n;i++)
                    csets[i].insert(idx);
            }
        }
        
        ll ans = 0;
        for(int i = 0;i<n;i++) 
            ans += (ll)cvals[i] * (ll)(n - csets[i].size());
        for(int i = 0;i<n;i++) 
            ans += (ll)rvals[i] * (ll)(n - rsets[i].size());
        return ans;   
    }

    long long matrixSumQueries_v03(int n, vector<vector<int>>& queries) {
        ll ans = 0;
        ll maxv = (ll)n*(ll)n;
        ll cnt = 0;
        vector<int> cols_changed = vector<int>(n,0);
        vector<int> rows_changed = vector<int>(n,0);
        unordered_set<int> rows_unchanged = unordered_set<int>();
        unordered_set<int> cols_unchanged = unordered_set<int>();        
        for(int i = 0;i<n;i++) {
            rows_unchanged.insert(i);
            cols_unchanged.insert(i);
        }

        int m = queries.size();
        for(int i = m-1 ; i>=0; i--) {
            vector<int> &q = queries[i];
            int type=q[0], idx=q[1], val=q[2];
            
            if(type == 0 && cols_changed[idx] == 0) {//change columns
                cols_changed[idx] = 1;
                cols_unchanged.erase(idx);
                
                for(auto &j:rows_unchanged) {
                    ans+=val;
                    cnt++;                    
                }
            } else if(type == 1 && rows_changed[idx] == 0){//change rows
                rows_changed[idx] = 1;
                rows_unchanged.erase(idx);
                
                for(auto &j:cols_unchanged) {
                    ans+=val;
                    cnt++;                    
                }
                           
            }
            if(cnt>=maxv) break;
        }
        
        return ans;
    }



};