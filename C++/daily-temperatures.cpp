class Solution {
    //https://leetcode.com/problems/daily-temperatures
public:
    /*
      0  1  2. 3. 4. 5. 6. 7
    [73,74,75,71,69,72,76,73]
    [ 1, 1, 4, 2, 1, 1, 0, 0]
      +--+
         +--+
            +-----------+
               +-----+
                  +--+
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {        
        int n = temperatures.size(),j=0;
        vector<int> &A = temperatures, ans=vector<int>(n,0);
        stack<int> stk;
        while(j<n) {
            if(!stk.empty() && A[j]>A[stk.top()]) {
                ans[stk.top()]=j-stk.top();
                stk.pop();
            } else {
                stk.push(j++);
            }
        }
        return ans;
    }

    vector<int> dailyTemperatures_v02(vector<int>& temperatures) {        
        int n = temperatures.size();
        vector<int> &A = temperatures, ans=vector<int>(n,0);
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i<n;i++) {
            while(!stk.empty() && A[i]>A[stk.top()]) {
                ans[stk.top()]=i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }

    vector<int> dailyTemperatures_v01(vector<int>& temperatures) {        
        int n = temperatures.size();
        vector<int> &A = temperatures, ans=vector<int>(n,0);
        for(int i = 0; i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(A[j]>A[i]) {
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};