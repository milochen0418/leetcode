class Solution {
    //https://leetcode.com/problems/long-pressed-name
    //article https://leetcode.com/problems/long-pressed-name/discuss/3097476/C%2B%2B-One-Pass-O(N)
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.length(), m=typed.length();
        char c = 0;
        int cnt = 0;
        int j = 0;
        for(int i = 0; i<n;i++) {
            if(c!=name[i]) {
                c=name[i];
                cnt=1;
            } else {
                cnt++;
            }
            
            if(i+1>=n||c != name[i+1] ) {
                //printf("i=%d, cnt=%d ... start j=%d\n",i,cnt,j);
                int t = cnt;
                while(j<m && c==typed[j]){
                    t--;
                    j++;
                }
                if(t>0) return false;
            }
        }
        if(j<m) return false;
        //printf("start j=%d\n",j);
        return true;
    }
};