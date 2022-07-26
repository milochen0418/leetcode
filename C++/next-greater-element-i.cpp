class Solution {
    //https://leetcode.com/problems/next-greater-element-i/
public:    
    /*
        Observation
        Your input
        [5,4,1,2,3]
        [5,4,1,2,3] -> convert to [-1,-1,2,3,-1]
        [6,5,4,3,2,1,8,7]
        [6,5,4,3,2,1,8,7] -> convert to [8,8,8,8,8,8,-1,-1]
    */
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp; 
        //display_vector_int("nums2", nums2);
        
        for(int i = 0; i < nums2.size();i++) mp[nums2[i]] = i;
        
        nums2.push_back(INT_MAX);
        stack<int> stk;
        for(int i = nums2.size()-1;i>=0;i--) {
            if(stk.empty()) {
                stk.push(nums2[i]);
                continue;
            }
            while(nums2[i]>=stk.top()) stk.pop();
            int e = stk.top();//case i<stk.top()
            stk.push(nums2[i]);
            nums2[i]=e;
        }
        for(int i = 0; i<nums2.size();i++) if(nums2[i]==INT_MAX) nums2[i]=-1;
        
        
        //display_vector_int("nums2", nums2);
        
        
        for(int i = 0; i < nums1.size();i++) {
            int j = mp[nums1[i]];
            nums1[i] = nums2[j];
        }
        return nums1;
        
    }
    void display_vector_int(string name, vector<int>& a) {
        printf("%s = ", name.c_str());
        for(auto &i:a) printf("%d, ", i);
        printf("\n");
    }
};
/* Test-Case
[6,5,4,3,2,1,8,7]
[6,5,4,3,2,1,8,7]
[5,4,1,2,3]
[5,4,1,2,3]
[1,3,5,2,4]
[6,5,4,3,2,1,7]

*/