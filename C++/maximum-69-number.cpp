class Solution {
    //https://leetcode.com/problems/maximum-69-number/
    //article https://leetcode.com/problems/maximum-69-number/discuss/3027912/C%2B%2B-Stack
public:
    int maximum69Number (int num) {
        stack<int> s;
        int first6notound = 1;
        while(num>0) {
            int r = num%10;
            s.push(r);
            num/=10;
        }
        while(!s.empty()) {
            int r = s.top();
            if(first6notound && r==6) {
                first6notound = 0;
                r=9;
            }
            num=num*10+r;
            s.pop();
        }
        return num;
    }
};