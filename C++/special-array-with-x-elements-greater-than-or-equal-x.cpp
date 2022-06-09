class Solution {
    //https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x
public:
    int specialArray(vector<int>& a) {
        return specialArrayBySorting(a);
    }

    //O(Nlog(N)) 
    int specialArrayBySorting(vector<int>& a) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        /*
        a[0]>=1 -> reutrn 1;
        a[1]>=2 -> return 2;
        a[2]>=3 -> return 3;
        */

        int ans = -1;
        for(int x = 0; x<n;x++) {
            if(a[x]>=x+1) {
                //Think about the case [[9,7,6,5] and [9,7,6,5,4].
                //make sure there is no next item larger than x+1
                if(x+1>=n || !(a[x+1]>=x+1)) {
                    ans = x+1;    
                }
            }
        }
        return ans;
    }    

    //O(N^2)
    int specialArrayByBruteForce(vector<int>& a) {
        int n = a.size();
        for(int x = 0; x<=n;x++) {
            int cnt = 0;
            for(int i = 0; i<n;i++) {
                if(a[i]>=x) cnt++;
            }
            if(cnt==x) return x;
        }
        return -1;
    }
};