class Solution {
    //https://leetcode.com/problems/distribute-money-to-maximum-children
public:
    int distMoney(int money, int children) {
        money-=children;
        if(money<0) return -1;
        int ans = money / 7; 
        int r = money % 7;
        children -= ans;
        if(children<0) {
            children+=ans;//add back original children
            if(money != children*7) {
                return children -1;    
            } else {
                return children;
            }
        } else if(children==0) {
            if(r!=0) 
                return ans - 1;
            else 
                return ans;
        } else if(children == 1) {
            if(r==3)
                return ans - 1;
            else 
                return ans;
        } else if (children >= 2) {
            return ans;
        }
        return -1;
    }
};