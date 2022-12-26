class Solution {
    //https://leetcode.com/problems/minimum-cost-to-connect-sticks/
public:
    int connectSticks(vector<int>& sticks) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> minQ;
        for(auto &i: sticks) minQ.push(i);
        while(minQ.size()>1) {
            int a = minQ.top();
            minQ.pop();
            int b = minQ.top();
            minQ.pop();
            ans+=(a+b);
            minQ.push(a+b);
        }        
        return ans;
    }


    int connectSticks_N2logN(vector<int>& sticks) {
        vector<int>& A = sticks;
        int ans=0;
        while(A.size()>1) {
            sort(A.begin(), A.end(),greater<int>());
            A[A.size()-2] += A.back();
            ans+=A[A.size()-2];
            A.pop_back();
        }
        return ans;
    }
};