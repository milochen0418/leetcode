class Solution {
    //https://leetcode.com/problems/longest-turbulent-subarray
    //article https://leetcode.com/problems/longest-turbulent-subarray/discuss/4379337/C%2B%2B-easy-solution-with-explain-O(N)-time
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<char> v;
        v.push_back('=');
        for(int i = 0; i<arr.size()-1;i++) {
            if(arr[i] <arr[i+1]) v.push_back('+');
            if(arr[i]==arr[i+1]) v.push_back('=');
            if(arr[i] >arr[i+1]) v.push_back('-');
        }
        v.push_back('=');
        
        int ans = 1, cnt = 0, n = v.size();
        char lastc = v[0];
        for(int i = 0;i<n;i++) {
            if(v[i]=='=') {
                ans = max(ans, cnt);
                cnt = 0;
                while(i<n && v[i]=='=')i++;
                if(i<n) lastc = v[i];
                cnt=2;
                continue;
            }
            if(v[i]!=lastc) {
                cnt++;
                lastc=v[i];
            } else {//v[i]==lastc
                ans=max(ans, cnt);
                cnt=2;
                lastc=v[i];
            }
        }
        return max(1,ans);
    }
};