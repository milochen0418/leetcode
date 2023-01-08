class Solution {
    //https://leetcode.com/problems/categorize-box-according-to-criteria
    //article : https://leetcode.com/problems/categorize-box-according-to-criteria/discuss/3020301/C%2B%2B-easy
public:
    string categorizeBox(int length, int width, int height, int mass) {
        typedef long long ll;
        ll volume =(ll)length * (ll)width *(ll)height;
        bool is_bulky = volume>=1e9||length>=1e4||width>=1e4||height>=1e4;
        bool is_heavy = mass>=100;
        if(is_bulky && is_heavy) return "Both";
        if(is_bulky) return "Bulky";
        if(is_heavy) return "Heavy";
        return "Neither";
    }
};