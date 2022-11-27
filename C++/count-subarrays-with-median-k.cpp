class Solution {
public:
    /*
    [3,2,1,4,5], k = 4
    [-1,-1,-1,0,1]
    
    */
    vector<int> vk;
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        //vector<int> vk = vector<int>(n,0);
        vk = vector<int>(n,0);
        for(int i = 0;  i<n; i++) {
            if(k==nums[i]) 
                vk[i] = 0;
            else if(nums[i] <k) {
                vk[i] = -1;
            } else {//k<nums[i]
                vk[i] = 1;
            }
        }
        //let vk = prefix sum of vk
        for(int i = 1; i<vk.size();i++) {
            vk[i] = vk[i-1] + vk[i];
        }
        /*
        printf("getSum(2,4) = %d\n",getSum(2,4,vk));
        printf("getSum(3,4) = %d\n",getSum(3,4,vk));
        printf("getSum(3,3) = %d\n",getSum(3,5,vk));
        printf("\n\n");
        */
        
        /*
        for this case, 
        [3,2,1,4,5], k = 4
        [-1,-1,-1,0,1]
        getSum(2,4) = 0 [1,4,5]
        getSum(3,4) = 1 [4,5]
        getSum(3,3) = 0 [4]
        if((R-L) %2 == 1) getSum(L,R) should be 1
        if((R-L) %2 == 0) getSum(L,R) should be 0
        Summary 
        if(getSum(L,R) == (R-L)%2) ans++;
        */
        int q = 0;//index of k
        for(int i = 0;i<n;i++) {
            if(nums[i] == k) {
                q = i;
                break;
            }
        }
        int ans = 0;
        //for(int L = 0; L<q;L++) {
        for(int L = 0; L<=q;L++) {
            //for(int R=q+1;R<n;R++) {
            for(int R=q;R<n;R++) {            
                //int sum = getSum(L,R);
                //printf("L=%d, R=%d, num = %d,sum(L,R)=%d\n", L, R, R-L+1, sum);
                if(getSum(L,R) == (R-L)%2) {
                    //printf("L=%d, R=%d\n", L, R);
                    //printf("cnt up\n");
                    ans++;
                }
            }
        }
        
        //printf("\n\n");
        return ans;
        
        
    }
    //int getSum(int L, int R, vector<int>& vk) {
    int getSum(int L, int R) {
        //nums = [-1,-1,-1, 0, 1]
        //->vk = [-1,-2,-3,-3,-2]
        //presume vk is array of showing prefix sum of nums
        //getSum(L=0,R=2) is sum of nums[0..2]. it is vk[R] - vk[L-1]. if L-1<0, then vk_L_1 = 
        //getSum(L=0,R=2) is vk_R - vk_L_1 
        int vk_L_1 = (L==0)?0:vk[L-1];
        int vk_R = R<vk.size()?vk[R]:vk[vk.size()-1];
        return vk_R-vk_L_1;
    }
};