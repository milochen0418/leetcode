class Solution {
    //https://leetcode.com/problems/best-sightseeing-pair
    //article https://leetcode.com/problems/best-sightseeing-pair/discuss/2354047/C%2B%2B-or-time-O(N)-space-O(1)-or-Easy-to-Understand
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //From backward node to observe who is the best partner to make
        //the best value from the past record.
        //The backward node and this value would be the best solution.
        //From above procedure, you can travel all point of backward in values.
        //In our solution, one of values[] will in backward side. ant that's answer.
        //
        //So we just need to find out that rule to decide who become the best forward
        //node for the backward node.
        
        //assume i<j<k
        //v(i,k) = value[i]+value[k]-(k-i) ...(1)
        //v(j,k) = value[j]+value[k]-(k-j) ...(2)
        //Between v(i,k) and v(j,k), who is the best?
        //If we need j instead i, then it must satsify the condition v(j,k)>v(i,k)
        /*
        v(j,k)-v(i,k) > 0
        value[j]-value[i]+(j-i)>0
        If value[j]+(j-i) > value[i], then value[j] can instead value[j]
        */
        int n = values.size(), ans = 0, i =0;
        for(int j = 1;j<n;j++) {
            ans = max(ans, values[i]+values[j]+i-j);
            if(values[j]+(j-i)>values[i]) i=j;
        }
        return ans;
    }

    int maxScoreSightseeingPair_v01(vector<int>& values) {
        //for i < j,
        //  values[i] + values[j] + i - j
        //= (values[j]-j) + (i+values[i]);
		//So always keep the top value for i+values[i]
        int n = values.size();
        int ans = INT_MIN;
        int top = 0+values[0];
        for(int j = 1; j<n; j++) {
            ans = max(ans, (values[j]-j) + top);
            top = max(top,(j+values[j]));
        }
        return ans;
    }
};