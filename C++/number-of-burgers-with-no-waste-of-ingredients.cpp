class Solution {
    //https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients
    //article https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/discuss/4363504/C%2B%2B-O(1)-time-O(1)-space
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices%2==1) return {};
        if(tomatoSlices/2<cheeseSlices) return {};
        if(tomatoSlices/4>cheeseSlices) return {};
        int x = (tomatoSlices - 2*cheeseSlices)/2;
        int y = cheeseSlices - x;
        return {x,y};
    }
};