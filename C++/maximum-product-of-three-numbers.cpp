class Solution {
    //https://leetcode.com/problems/maximum-product-of-three-numbers/
public:
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)    
    #define print_container(name) printf("%s = [",#name);for(auto &i:name)printf("%d,",i);printf("]\n");    
    int maximumProduct(vector<int>& nums) {
        printf("\n");
        print_container(nums);
        int n = nums.size();
        if(n==3) return nums[0]*nums[1]*nums[2];
            
        sort(nums.begin(),nums.end(),[](auto &lhs, auto &rhs){
            if(abs(lhs)==abs(rhs))
                return lhs>rhs;
            else 
                return abs(lhs)>abs(rhs);
        });
        int negCnt=0, posCnt=0,zeroCnt =0;
        print_container(nums);
        
        
        vector<int> negv;
        vector<int> posv;
        
        for(auto &i:nums) {
            if(i<0) {
                negv.push_back(i);
                negCnt++;
            }
            else if(i==0) {
                zeroCnt++;
            }
            else if(i>0) {
                posv.push_back(i);
                posCnt++;
            }
        }
        
        print_container(posv);
        print_container(negv);
        printf("n=%d, negCnt=%d, posCnt=%d\n",n,negCnt, posCnt);
        if(posCnt==0 && zeroCnt>0) {
            printf("go case 0.0\n");
            return 0;
        }
        if(n==negCnt) {
            printf("go case 0.1\n");
            return nums[n-1]*nums[n-2]*nums[n-3];
        }
        if(negCnt + posCnt<3) {
            printf("go case 0.2\n");
            return 0;
        }
        if(nums[0]>=0 && nums[1]>=0 && nums[2]>=0) {
            printf("go case 1\n");
            return posv[0]*posv[1]*posv[2];
        } else {
            if(negCnt == 1) {
                if(zeroCnt>0) {
                    printf("go case 2.1\n");
                    return 0;
                }
                printf("go case 2\n");
                return posv[0]*posv[1]*posv[2];
            } else {
                printf("go case 3\n");
                int can = negv[0]*negv[1]*posv[0];
                if(posv.size()>=3) can = max(can,posv[0]*posv[1]*posv[2]);
                return can;
            }
        }
        
    }
};