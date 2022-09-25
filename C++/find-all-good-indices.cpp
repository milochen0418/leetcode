class Solution {
    //https://leetcode.com/problems/find-all-good-indices/
    //Add article https://leetcode.com/problems/find-all-good-indices/discuss/2621324/C%2B%2B-or-array-approach-or-explanation
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        /*
        k <= i < n - k good 
        for example, k = 2 n = 10
        2<=i<8 is good.   0,1 is not good. 8,9 is not good
        */
        /*
        
        Idea 1:
        //[2,1,1,1,3,4,1]
        non-increasing
        [0,3] -> [2,1,1,1]
        [5,6] -> [4,1]
        
        non-decreasing
        [3,5] -> [1,3,4]
        
        Analysis 
        k=2, n = 7, so range of i is in 2<=i<5 
        */
        
        /*
        Idea 2:
        non-increasing
        [2,1,1,1,3,4,1]
        [1,2,3,4,1,1,2] <- NI array
        
        [1,2,3,4,1,1,2] Expect NI array
        
        non-descreasing
        [2,1,1,1,3,4,1]
        [1,1,2,3,4,5,1] <- ND array (wrong) 
        //[1,3,2,1,2,1,1] <- ND array(find non-increasing from right to left ) ??
        [1,5,5,5,5,5,1] <--max val array  MVA. so Expect ND array[i] = MVA[i] - ND_wrong[i]
        
        [1,5,4,3,2,1,1]        Our Expect ND array
        
        case i=2, NI[i-1] = 2
        case i=2, ND[i+1] = 3 
        
        case i=3, NI[i-1] = 3
        case i=3, ND[i+1] = 4
        
        case i=4, NI[i-1] = 4
        case i=4, ND[i+1] = 1
        */
        
        int n = nums.size();
        vector<int> NI = vector<int>(n,1);
        vector<int> ND = vector<int>(n,1);
        int L = 0, ND_local_max = 1;
        for(int i = 1; i<n;i++) {
            if(nums[i-1]>=nums[i]) NI[i] = NI[i-1]+1;
            if(nums[i-1]<=nums[i]) {
                ND[i] = ND[i-1]+1;
                ND_local_max = ND[i];
            } else {
                int R = i-1;
                //printf("process L=%d, R=%d, with local_max = %d\n", L,R, ND_local_max);
                /*
                    for(int j = L;j<=R;j++) {
                        ND[j] = ND_local_max - ND[j] + 1;
                    }                    
                
                */
                if(R>L) {
                    for(int j = L;j<=R;j++) {
                        ND[j] = ND_local_max - ND[j] + 1;
                    }                    
                }
                L = i;
            }
        }
        //edge case for this test case [878724,201541,179099,98437,35765,327555,475851,598885,849470,943442] 4
        //If you don't process it, then ND = 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 
        if(L<n-1) {
            int R = n-1;
            /*
                for(int j = L;j<=R;j++) {
                    ND[j] = ND_local_max - ND[j] + 1;
                }                    

            */
            if(R>L) {
                for(int j = L;j<=R;j++) {
                    ND[j] = ND_local_max - ND[j] + 1;
                }                    
            }
        }
        /*
        printf("NI = ");
        for(auto &i:NI) printf("%2d,", i);
        printf("\n");
        
        printf("ND = ");
        for(auto &i:ND) printf("%2d,", i);
        printf("\n");
        */
        vector<int> ans;
        for(int i = k; i<n-k;i++) {
            if(NI[i-1]>=k && ND[i+1]>=k) ans.push_back(i);    
        }        
        return ans;
        /*
        for(int i = k; i<n-k;i++) {
            
        }
        */
        
    }
};