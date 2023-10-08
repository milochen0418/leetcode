class Solution {
    //https://leetcode.com/problems/account-balance-after-rounded-purchase
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if(purchaseAmount>100)
            return 0;
        else     
            return  10* (10 - ( (purchaseAmount/10) + (purchaseAmount%10>=5) ));
    }
};