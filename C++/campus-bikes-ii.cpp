class Solution {
    //https://leetcode.com/problems/campus-bikes-ii/
public:
    vector<vector<int>> dis;
    vector<int> test={0,1,2};
    void show(vector<int>& v) {
        for(auto &i:v) 
            printf("%d, ",i );
        printf("\n");
    }
    
    //C++ lambda example from https://learn.microsoft.com/zh-tw/cpp/cpp/examples-of-lambda-expressions?view=msvc-170
    //function<int(int, int)> f2 = [](int x, int y) { return x + y; };
    
    void permutate(vector<int>&v, int col, function<void(vector<int>&)>lambda) {
        if(col==v.size()-1) lambda(v);
        for(int j = col; j<v.size();j++) {
            swap(v[col],v[j]);
            permutate(v, col+1, lambda);
            swap(v[col],v[j]);
        }
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        
        permutate(test,0, [](vector<int>& v) { 
            for(auto &i:v) printf("%d,",i );
            printf("\n");
        });
        return 0;
        
        int n = workers.size(), m = bikes.size();
        int ans = INT_MAX;
        dis = vector<vector<int>>(n, vector<int>(m,0));
        for(int i = 0; i<n;i++) 
            for(int j = 0; j<m;j++) 
                dis[i][j] = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
        
        vector<int> A = vector<int>(m,0);
        for(int i = 0; i<m;i++) A[i] = i;
        do {
            int sum_dis = 0;
            for(int i = 0;i<n;i++) 
                sum_dis += dis[i][A[i]];
            ans = min(ans, sum_dis);
        } while( next_permutation(A.begin(), A.end()) );
        return ans;
    }
};