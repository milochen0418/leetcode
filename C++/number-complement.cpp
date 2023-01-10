class Solution {
    //https://leetcode.com/problems/number-complement
public:
    int findComplement(int num) {
        stack<int> s;
        while(num>0){
            s.push(num%2);
            num/=2;
        }
        while(!s.empty()) {
            num=num*2 + (s.top()==0);
            s.pop();
        }
        return num;
    }
};