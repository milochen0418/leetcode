class Solution {
    //https://leetcode.com/problems/number-of-students-unable-to-eat-lunch
    //article https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/discuss/2955782/C%2B%2B-or-O(N)
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ans = 0, n = students.size(), i=0;
        vector<int> w = vector<int>(2,0);
        for(auto &i:students) w[i]++;
        for(i = 0;i<n;i++) {
            if(w[sandwiches[i]]==0)break;
            --w[sandwiches[i]];
        }
        return n-i;
    }
};