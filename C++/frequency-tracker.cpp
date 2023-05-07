class FrequencyTracker {
    //https://leetcode.com/problems/frequency-tracker/
public:
    unordered_map<int,int>mp_freq;
    unordered_map<int,int>mp_ans;
    
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int old_freq = mp_freq[number];
        mp_freq[number]++;
        int new_freq = mp_freq[number];
        
        mp_ans[old_freq]--;
        mp_ans[new_freq]++;
    }
    
    void deleteOne(int number) {
        if(mp_freq.find(number) == mp_freq.end()) mp_freq[number] = 0; 
        if(mp_freq[number] == 0) return; 
        int old_freq = mp_freq[number];
        mp_freq[number]--;
        int new_freq = mp_freq[number];
        mp_ans[old_freq]--;
        mp_ans[new_freq]++;        
    }
    
    bool hasFrequency(int frequency) {
        if(mp_ans.find(frequency) == mp_ans.end()) mp_ans[frequency] = 0;
        if(mp_ans[frequency]>0) return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */