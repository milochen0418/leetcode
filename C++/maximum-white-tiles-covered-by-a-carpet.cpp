class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        //  [         ]
        //[0,1,1,1,0,0,0,1,1,1,1,0,0,1,1]
        //    [         ]
        //      [         ]
        
        sort(tiles.begin(), tiles.end(), [](auto& lhs,auto& rhs){
            return lhs[0]<rhs[0];
        });
        vector<int> v;
        vector<int> total;
        int n = tiles.size();
        for(auto& t:tiles) t.push_back(t[1]-t[0]+1);
        
        for(auto& t:tiles) {
            v.push_back(t[0]);
            total.push_back(t[1] - t[0] + 1);
        }
        int k = carpetLen;
        int ans=0;
        for(int i = 0; i<n;i++) { 
            int L = v[i];
            //int L = tiles[i][0];
            int R = v[i]+k-1;
            //int R = tiles[i][0]+k-1; 
            
            //figure out who cover R.
            int end_j=i;
            for(int j = i; j<n;j++ ) {
                if(R>=v[j]) {
                    end_j = j;
                } else {
                    break;
                }
            }
            
            
            int sum = 0;
            for(int k = i; k<end_j;k++) {
                sum += total[k];
                //sum += tiles[k][2];
            }
            if(R > tiles[end_j][1]) {
                sum += total[end_j];
                //sum += tiles[end_j][2];
            } else {
                //sum += (R-v[i]+1);
                sum += (R-v[end_j]+1);
                //sum += (R-tiles[i][0]+1);
            }
            ans = max(ans,sum);
        }
        return ans;
    }
    
    int memoryExceeded(vector<vector<int>>& tiles, int carpetLen) { 
        //a=[0,1,1,1,0,0,1,1,1,1,0]
        //s=[0,1,2,3,3,3,4,5,6,7,0] //prefix sum of a
        //a[2..8] = [1,1,0,0,1,1,1] = 5
        //a[2..8] = a[0..8] = a[0..1] = 6 - 1 = 5
        //so we say that a[i..j] = a[0..j] = a[0..i-1]
        using ll = int;
        int n = 1e9/100;
        //vector<ll> v = vector<ll>(n,0);
        vector<ll> prefixSum = vector<ll>(n,0);
        vector<ll>& v = prefixSum;
        for(auto &t: tiles) {
            int L = t[0];
            int R = t[1];
            for(int i = L; i<=R;i++) v[i]=1;
        }
        for(int i = 0; i<n;i++) {
            ll L = (i==0)?0:prefixSum[i-1];
            prefixSum[i] = L + v[i];
        }
        ll ans = 0; 
        int k = carpetLen;
        for(int i = 0; i<=n-k;i++) {
            ll candidate = prefixSum[i+k-1] - prefixSum[i];
            ans = max(ans, candidate);
        }
        
        return ans;
        
    }
};