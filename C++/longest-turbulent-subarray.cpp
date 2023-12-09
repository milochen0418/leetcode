class Solution {
    //https://leetcode.com/problems/longest-turbulent-subarray
    //article https://leetcode.com/problems/longest-turbulent-subarray/discuss/4379337/C%2B%2B-9-lines-One-Pass-O(N)-and-space-O(1)-with-explain
    //article https://leetcode.com/problems/longest-turbulent-subarray/discuss/4382428/C%2B%2B-simple-7-lines-time-O(N)-space-O(1)-with-explain
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), ans=1, cnt=0, lastd=0,d=0;
        for(int i=-1; i<=n; i++,lastd=d) {
            d = (i<0||i>=n-1||arr[i+1]==arr[i])?0:((arr[i+1]-arr[i])>0?1:-1);
            if(d==0 || d==lastd) ans = max(ans, cnt);//compare cnt to ans when expected sequence stop
            cnt = (d*lastd == -1) ? cnt+1 : 2*abs(d);//cnt+1 when expected sequence keep going. Here, we set cnt=0 when arr[i+1]==arr[i]  and cnt=2 otherwise.
        }
        return ans;
    }

    int maxTurbulenceSize_v05(vector<int>& arr) {
        char lastc = '=';
        int n = arr.size(), ans=1, cnt=0;
        for(int i=-1; i<=n; i++) {
            char ch = (i<0||i>=n-1||arr[i]==arr[i+1])?'=':(arr[i]<arr[i+1]?'+':'-');
            if(ch=='=' || ch==lastc) ans = max(ans, cnt);
            cnt = (ch+lastc == '+'+'-') ? cnt+1 : 2*(ch!='=');
            lastc = ch;
        }
        return ans;
    }

    int maxTurbulenceSize_v04(vector<int>& arr) {
        char lastc = '=';
        int n = arr.size(), ans=1, cnt=0;
        for(int i=-1; i<=n; i++) {
            char ch = (i<0||i>=n-1||arr[i]==arr[i+1])?'=':(arr[i]<arr[i+1]?'+':'-');
            if(ch=='=' || ch==lastc) {
                ans = max(ans, cnt);
                cnt = ch =='='?0:2;
            } else if( ch + lastc == '+' + '-') {
                cnt++;
            } else{
                cnt=2;
            }
            lastc = ch;
        }
        return ans;
    }
    int maxTurbulenceSize_v03(vector<int>& arr) {
        char lastc = '=';
        int n = arr.size(), ans=1, cnt=0;        
        for(int i=-1; i<=n; i++) {
            char ch = (i<0||i>=n-1||arr[i]==arr[i+1])?'=':(arr[i]<arr[i+1]?'+':'-');
            if(ch=='=') {
                ans = max(ans, cnt);
                cnt=0;
            } else {
                if(ch!=lastc) {
                    cnt = lastc=='='?2:cnt+1;
                } else {
                    ans=max(ans, cnt);
                    cnt=2;
                }
            }
            lastc = ch;
        }
        return ans;
    }

    int maxTurbulenceSize_v02(vector<int>& arr) {
        char lastc = '=';
        int n = arr.size(), ans=1, cnt=0;
        function<char(int i)> get_curr = [&arr,&n](int i) {
            if(i<0 || i>=n-1 || arr[i]==arr[i+1]) return '=';
            return (arr[i] <arr[i+1])?'+':'-';
        };
        
        for(int i=-1; i<=n; i++) {
            char ch = get_curr(i);
            if(ch=='=') {
                ans = max(ans, cnt);
                while(i<=n && get_curr(i)=='=')i++;
                if(i<=n) lastc = get_curr(i);
                cnt=2;
                continue;                
            } 
            if(ch!=lastc) {
                cnt++;
            } else {
                ans=max(ans, cnt);
                cnt=2;
            }
            lastc=ch;
        }
        return max(1,ans);
    }


    int maxTurbulenceSize_v01(vector<int>& arr) {
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