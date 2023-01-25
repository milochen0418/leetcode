class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        int n = 10;
        vector<int> stk;
        function<void(int,int)> sol=[&](int i, int r){
            if(r<0) return;
            if(i==n && r>0) return;
            if(i==n) {
                
                for(auto i:stk) printf("%d",i);
                printf("\n");
                return;
            }
            //r: remaind number of one that still not put in
            //i: range [i..n] begin index i to n=10
            
            stk.push_back(1);
            sol(i+1,r-1);
            stk.pop_back();
            stk.push_back(0);
            sol(i+1,r);
            stk.pop_back();            
        };
        sol(0,n);
        printf("\n");
        sol(0,0);
        printf("\n");
        sol(0,n-1);
        printf("\n");
        sol(0,1);
        printf("\n");
        
        //You can call sol(0,0..n);
        return vector<string>();
    }
};