class Solution {
    //https://leetcode.com/problems/best-sightseeing-pair
    //article https://leetcode.com/problems/best-sightseeing-pair/discuss/2354047/C%2B%2B-or-time-O(N)-space-O(1)-or-Easy-to-Understand
public:
    int maxScoreSightseeingPair(vector<int>& values) {
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