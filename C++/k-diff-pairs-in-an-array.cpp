class Solution {
    //https://leetcode.com/problems/k-diff-pairs-in-an-array/
public:
    
    int findPairs(vector<int>& nums, int k) {
        int cnt=0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n<=1) return 0;
                
        
        int idx = 0;
        bool cnt_same = false;
        for(auto num: nums) {
            if(nums[idx] != num) {
                cnt_same = false;
                nums[++idx] = num;
            }  else {
                if(cnt_same == false) {
                    cnt_same = true;
                    cnt++;
                }                
            }
        }
        if(k==0) { 
            return cnt;
        } else {
            cnt = 0;
        }
        n = idx + 1; //number of k non-repeat element in-place. 
        if(n<=1) return 0;
        
        int i =0, j=1;
        while( i<n && j<n) {
            if(nums[j] - nums[i]  >  + k)  {
                //i++;
                if(++i==j) j++;
            } 
            else if(nums[j] - nums[i] < k ){
                j++;
            } 
            else { //case nums[i] == nums[j]
                cnt++;
                i++;
                j++;
            }            
        }
        return cnt;
    }
    
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;  
        }
    };
    
    
    int answer1(vector<int>& nums, int k) {
        unordered_set< pair<int,int>, pair_hash> s;
        int cnt=0;
        int n = nums.size();
        for(int i = 0; i<n ;i++) {
            for(int j=i+1; j<n;j++) {
                if(abs(nums[i] - nums[j])==k) {
                    int big = nums[j]>nums[i]?nums[j]:nums[i];
                    int small = nums[j]>nums[i]?nums[i]:nums[j];
                    if(s.find({big, small}) == s.end()){
                        s.insert({big, small});
                        cnt++;    
                    }
                    
                }
            }
        }
        return cnt;
    }
};


/* test-case

[1,1,1,1,2,2,3,4,4]
0
[1,1,3,5,5,3]
2
[3,1,4,1,5]
2
[1,2,3,4,5]
1
[1,3,1,5,4]
0
*/