class Solution {
    //https://leetcode.com/problems/contains-duplicate-iii/
    /* In https://www.onlinegdb.com/online_c++_compiler. 
    
#include <iostream>
using namespace std;
#include<set>
#include<vector>
int main()
{
    std::set<int> s;
    s.insert(1); 
    s.insert(30);
    s.insert(80);
    vector<int> v = {-10, 15, 30, 31, 60, 100};
    for(auto num: v) {
        cout<<num <<"\tLB="<<*s.lower_bound(num )<<"\tUB="<<*s.upper_bound(num)<<"\n";
    }
    return 0;
}    

Result:
-10     LB=1    UB=1
15      LB=30   UB=30
30      LB=30   UB=80
31      LB=80   UB=80
60      LB=80   UB=80
100     LB=3    UB=3
upper_bound/lower_bound explain
https://stackoverflow.com/questions/41958581/difference-between-upper-bound-and-lower-bound-in-stl
    */
    /*
    test-cases
[1,2,3,1]
3
0
[1,0,1,1]
1
2
[1,5,9,1,5,9]
2
3
[8,7,15,1,6,1,9,15]
1
3
    */
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++) {
            if(i>k){
                s.erase(nums[i-k-1]);
            }
            int num = nums[i];
            if(s.find(num) == s.end()) {
                s.insert(num);
            } else {
                return true;
            }
        }
        return false;
    }
};