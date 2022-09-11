class Solution {
    //https://leetcode.com/problems/most-frequent-even-element/
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> freq_mp;
        for(int i = 0; i < nums.size(); i++)  {
            if(nums[i]%2==0) {
                freq_mp[nums[i]]++;
            }
        }
        
        int smallest_v= -1;
        int max_freq = 0;
        for(auto &[v,freq]: freq_mp) {
            //printf("[v,freq]=%d, %d\n", v, freq);
            if(freq == max_freq) { 
                if(v<smallest_v) smallest_v= v;
            } else if(freq>max_freq) {
                smallest_v = v;
                max_freq = freq;
            }
        }
        return smallest_v;
    }
};