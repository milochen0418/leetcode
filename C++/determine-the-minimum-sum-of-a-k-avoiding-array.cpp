class Solution {
public:
/*
        //n=5, k=4 
        //1,2,4,5,6
        
        //n=6, k=5  5-avoding
        //1,2,5,6,7,8   ->  29
        
        //n=6, k=6
        //1,2,3,6,7,8 -> 27 
        
        //n=6, k=7
        //1,2,3,7,8,9 -> 30 
        
        //n=7, k=7
        //1,2,3,7,8,9,10 -> 40
        
        //n=6, k=8
        //1,2,3,4,8,9 -> 27 
        
        //Idea   
        //The sequence may like (a1=1,a2,a3...)     (k,k+1,k+ ...) s.t.
        //ai+aj<k 
*/
    int minimumSum(int n, int k) {
        if(n==1) return 1;
        vector<int> v = {1};
        for(int i = 2; i<k; i++) {
            if(i+v.back()>=k) break;
            v.push_back(i);
            if(v.size() == n) return report(v,n,k);
        }
        int L=max(2,k),R=n+k;
        for(int i = L; i<=R;i++) {
            v.push_back(i);
            if(v.size() == n) return report(v,n,k);
        }
        return report(v,n,k);
    }
    int report(vector<int> &v, int n, int k) {
        printf("\nn=%d, k=%d, v = ",n,k);
        for(auto &i:v) printf("%d, ",i);
        printf("\n");
        return accumulate(v.begin(), v.end(), 0);
    }
};