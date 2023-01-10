class Solution {
    //https://leetcode.com/problems/number-complement
public:
    int findComplement(int num) {
        //One Pass Stack
        stack<int> s;
        int ans=0;
        while(num>0 || !s.empty()){
            if(num) {
                s.push(num%2);
                num/=2;
            } else {
                ans=ans*2 + (s.top()==0);
                s.pop();
            }
        }
        return ans;
    }


    int findComplement_v01(int num) {
        //Two Pass Stack
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