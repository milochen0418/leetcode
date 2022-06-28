
class Solution {
    //https://leetcode.com/problems/meeting-scheduler
    //article https://leetcode.com/problems/meeting-scheduler/discuss/2210147/C%2B%2B-or-space-O(1)-time-O(-MlogM-%2B-NlogN-)
public:
    vector<int> minAvailableDuration(vector<vector<int>>& a1, vector<vector<int>>& a2, int duration) {
        sort(a1.begin(), a1.end(), [](auto&l, auto&r){return l[0] < r[0];});
        sort(a2.begin(), a2.end(), [](auto&l, auto&r){return l[0] < r[0];});
        int i1 =0, i2=0;
        while(i1<a1.size() && i2<a2.size()) {
            if(a2[i2][0] > a1[i1][1]) 
                i1++;
            else if(a2[i2][1] < a1[i1][0]) 
                i2++;
            else {//intersection case     
                int m = min(a2[i2][1],a1[i1][1]);
                vector<int>& item = (a2[i2][0] <= a1[i1][0])?a1[i1]:a2[i2];
                if(m - item[0] >= duration) 
                    return vector<int>{item[0], item[0]+duration};
                else 
                    (a1[i1][1]<a2[i2][1]?i1:i2)++;
            }
        }
        return vector<int>{};
    }

    void printf(const char *fmt, ...)
    {
        const bool debug=false;
        if(!debug) return;
        va_list args;
        va_start(args, fmt);
        vfprintf(stdout, fmt, args);
        va_end(args);
    }
    
    vector<int> minAvailableDurationDetail(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> ans = vector<int>();
        
        vector<vector<int>>&a1 = slots1;
        vector<vector<int>>&a2 = slots2;
        sort(a1.begin(), a1.end(), [](auto&lhs, auto&rhs) {
            return lhs[0] < rhs[0];
        });
        sort(a2.begin(), a2.end(), [](auto&lhs, auto&rhs) {
            return lhs[0] < rhs[0];
        });
        
        int i1 =0, i2=0;
        while(i1<a1.size() && i2<a2.size()) {
            if(a2[i2][0] > a1[i1][1]) {
                //a1 [    ]
                //a2           [    ]
                i1++;
            } else if(a2[i2][1] < a1[i1][0]) {
                //a1           [    ]
                //a2  [    ]
                i2++;
            } else { //intersection happened
                //if(a2[i2][1] > a1[i1][0]) {
                if(a2[i2][0] <= a1[i1][0]) {
                    printf("case 1:a1[%d]=[%d,%d], a2[%d]=[%d,%d] \n",i1,a1[i1][0],a1[i1][1],i2,a2[i2][0],a2[i2][1]);
                    // a1    [     ]
                    // a2 [    ]
                    if(min(a2[i2][1],a1[i1][1]) - a1[i1][0] >= duration) {
                        ans.push_back(a1[i1][0]);
                        ans.push_back(a1[i1][0]+duration);
                        return ans;
                    } else {
                        
                        if(a1[i1][1]>a2[i2][1]) {
                            printf("case1: i2++\n");
                            i2++;
                        } else {
                            printf("case1: i1++\n");
                            i1++;
                        }
                        
                    }
                //} else if(a1[i1][1] > a2[i2][0]) {
                } else if(a1[i1][0] < a2[i2][0]) {                    
                    printf("case 2:a1[%d]=[%d,%d], a2[%d]=[%d,%d] \n",i1,a1[i1][0],a1[i1][1],i2,a2[i2][0],a2[i2][1]);
                    
                    
                    // a1 [    ]
                    // a2   [      ]
                    //if(a1[i1][1] - a2[i2][0] >= duration) {
                    if(min(a1[i1][1],a2[i2][1]) - a2[i2][0] >= duration) {                    
                        ans.push_back(a2[i2][0]);
                        ans.push_back(a2[i2][0]+duration);
                        return ans;
                    } else {
                        if(a2[i2][1]>a1[i1][1]) {
                            printf("case2: i1++\n");
                            i1++;                               
                        } else {
                            printf("case2: i2++\n");
                            i2++;
                        }
                    }
                } else {
                    printf("Error in case a1[%d]=[%d,%d], a2[%d]=[%d,%d] \n",i1,a1[i1][0],a1[i1][1],i2,a2[i2][0],a2[i2][1]);
                    return ans;
                }
            }
        }
        return ans;
    }
};