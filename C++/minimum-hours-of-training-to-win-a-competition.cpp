class Solution {
    //https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition
    //article https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/discuss/2878778/C%2B%2B-or-prefix-sum
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum_energy = 0, n = energy.size(), hour = 0;
        for(auto &i:energy) sum_energy+=i;
        vector<int> presum_e = experience;
        for(int i=1;i<n;i++) presum_e[i]=presum_e[i]+presum_e[i-1];
        int e_max = presum_e[0];
        for(int i = 1;i<n;i++) e_max = max(e_max, experience[i]-presum_e[i-1]);
        if(!(initialEnergy>sum_energy)) hour += (sum_energy+1-initialEnergy);
        if(!(initialExperience>e_max)) hour += (e_max+1-initialExperience);
        return hour;
    }
};