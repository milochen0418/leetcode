class Solution {
    //https://leetcode.com/problems/lemonade-change
public:
    bool lemonadeChange(vector<int>& bills) {
        //change change would be 0,5 or 15 
        //how to give the change of 15? the first priority is 10+5
        //only give 5+5+5 when we have no choce of 10+5;
        //vector<int> change = vector<int>(21,0);
        vector<int> change = vector<int>(11,0);
        for(auto &i: bills) {
            if(i==5) {
                change[i]++;
            } else if(i==10) {
                if(--change[5] < 0 ) return false;
                change[i]++;
            } else { //i==20
                if(change[10]>0) {
                    --change[10];
                    if(--change[5] <0) return false;
                } else {
                    change[5]-=3;
                    if(change[5]<0) return false;
                    //change[20]++;
                }
            }
        }
        return true;
    }
};