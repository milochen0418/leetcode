class Solution {
    //https://leetcode.com/problems/kth-missing-positive-number/
    //article https://leetcode.com/problems/kth-missing-positive-number/discuss/2163408/C%2B%2B-or-find-aM-M-1-greater-k-greater-aM-1-(M-1)-1
public:
    int findKthPositive(vector<int>& a, int k) {
        a.push_back(INT_MAX);
        int n = a.size();
        int L=1,R=n-1;
        while(L<=R) {
            int M = L + (R-L)/2; //find a[M]-M-1 >= k > a[M-1]-(M-1)-1
            if(a[M]-M-1 >= k && (M-1<0 || k > a[M-1]-(M-1)-1) ) 
                return k-(a[M-1]-(M-1)-1) + a[M-1];
            if(a[M-1]-(M-1)-1 >= k) R=M-1; else L=M+1;
        }
        return k;
        
        /*              8
                    5   9
           1        6  10
       [0, 2, 3, 4, 7, 11]
       
       find k=3 missing positive number
       0,2,3 is in array
       Suppose t = # of e in a[] s.t. e <= k
       k+t is the kth positive missing number
       
       0,2,3,4  ,7
        1     56
          
       a[4] = 7 代表 [0..6] 的7個元素中 有a[0]a[1]a[2]a[3]佔用，剩下 有3個數是 missing number
       
       a[Q] = R 
       1-indexed array 
       a[0] = 1
       a[1] = 2
       a[2] = 3
       a[3] = 7 代很 [0...6] 的 7 個元素中 3 個佔完，剩下 
       
       a[Q] = R 代表 [0...R-1]這R 個元素中，有 Q 個元素已經被a[0]..a[R-1]佔完，
       所以說剩下有 R-Q 個  missing number.
       
       但我們是沒有  考慮 0  的
       因此  ,在 a[M] 值之前，總共有  a[M] - M - 1 個 missing number
       a[M] - M - 1 < k <= a[M] - M - 1
        */
    }
};