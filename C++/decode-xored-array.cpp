class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        /*
           Observation   
                      [01,00,10,01]
             arr = [01,00,10,01]                      
            encoded = [01,10,11]
        */
        vector<int> arr;
        arr.push_back(first);
        for(auto &i:encoded) arr.push_back(i^arr.back());
        return arr;
    }
};