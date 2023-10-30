class Bank {
    //https://leetcode.com/problems/simple-bank-system
    //article https://leetcode.com/problems/simple-bank-system/discuss/4227046/C%2B%2B-simple-solution-with-printf
public:
    typedef long long ll;
    int n;
    vector<long long>* pV;
    int cmdcnt;
    Bank(vector<long long>& balance) {
        n = balance.size();
        pV = &balance;
        cmdcnt=0;
    }
    
    bool transfer(int account1, int account2, long long money) {
        cmdcnt++;
        vector<ll> &v = *pV;
        if(account1<1 || account1>n) return false;
        if(account2<1 || account2>n) return false;
        //printf("[%d] before transfer [%d]=%ld, [%d]=%ld ,money=%ld\n", cmdcnt, account1, v[account1-1], account2, v[account2-1], money);
        
        if(v[account1-1]<money) return false;
        v[account1-1]-=money;
        v[account2-1]+=money;
        
        //printf("after transfer [%d]=%ld, [%d]=%ld ,money=%ld\n", account1, v[account1-1], account2, v[account2-1], money);

        return true;
        //v[account1]
    }
    
    bool deposit(int account, long long money) {
        cmdcnt++;
        vector<ll> &v = *pV;
        
        if(account<1 || account>n) return false;
        //printf("[%d]before desposit [%d]=%ld, money=%ld\n",cmdcnt, account, v[account-1], money);
        v[account-1] += money;
        //printf("after desposit [%d]=%ld, money=%ld\n", account, v[account-1], money);
        return true;
    }
    
    bool withdraw(int account, long long money) {
        cmdcnt++;
        vector<ll> &v = *pV;
        
        if(account<1 || account>n) return false;
        if(v[account-1]<money) return false;
        //printf("[%d]before withdraw [%d]=%ld, money=%ld\n", cmdcnt, account, v[account-1], money);
        v[account-1] -= money;
        //printf("after withdraw [%d]=%ld, money=%ld\n", account, v[account-1], money);
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */