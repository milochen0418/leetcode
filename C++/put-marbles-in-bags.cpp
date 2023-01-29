class Solution {
    //https://leetcode.com/problems/put-marbles-in-bags
public:
/*
Observation 
[1,3,5,1], k = 2
find k-1 cut between  1 3 5 1

For example  1 3|5 1. this cut '|' contribute the value 3+5 
If you make a second cut ,  1 3|5|1 . then first cut contribute 3+5. 
Second cut contrbute 5+1

For the maximum value, we want find the total contribution from top k-1 cut
For the minimum value, we want find the total contribution from lowest k-1 cut. 
Then the answer could be maximum - minumum

By the way, this observation is contributed by 哎呀呀 and ZZZ in LeetCode Contest after party. 
*/

    long long putMarbles(vector<int>& weights, int k) {
        typedef long long ll;
        vector<ll> v;
        for(int i =1;i<weights.size();i++) 
            v.push_back((ll)weights[i]+(ll)weights[i-1]);
        sort(v.begin(), v.end());
        ll minv=0,maxv=0;
        for(int i = 0;i<k-1;i++) minv+=v[i];
        reverse(v.begin(),v.end());
        for(int i = 0;i<k-1;i++) maxv+=v[i];
        return maxv-minv;
    }
};

