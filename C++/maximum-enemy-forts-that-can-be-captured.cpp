class Solution {
    //https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        int n = forts.size(); 
        
        for(int i = 0;i<n;i++) {
            if(1 == forts[i]) {
                for(int j = i+1; j<n;j++) {
                    if(forts[j]==1) break ;
                    if(forts[j]==-1) {
                        int dis = abs(i-j)-1;
                        ans = max(ans, dis);
                        break;
                    }
                }
                for(int j = i-1; j>=0;j--) {
                    if(forts[j]==1) break ;
                    if(forts[j]==-1) {
                        int dis = abs(i-j)-1;
                        ans = max(ans, dis);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};