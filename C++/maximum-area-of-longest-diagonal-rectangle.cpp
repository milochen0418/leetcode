class Solution {
    //https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        typedef long long ll;
        int n = dimensions.size();
        
        vector<ll> dis = vector<ll>(n,0);
        vector<ll> areas = vector<ll>(n,0);
        
        for(int i = 0; i<n;i++ ) { 
            ll length = dimensions[i][0];
            ll width = dimensions[i][1]; 
            ll di =  length*length + width*width;
            ll area = length*width;
            dis[i] = di;
            areas[i] = area;
        }
        
        int maxIdx = 0;
        for(int i = 0 ; i<n; i++) {
            if(dis[i] < dis[maxIdx]) continue;
            if(dis[i] > dis[maxIdx]) {
                maxIdx = i;
            } else {
                if(areas[i] > areas[maxIdx]) {
                    maxIdx = i;
                }
            }
        
        }
        
        return (int)areas[maxIdx];
        
    }
};