class Solution {
    //https://leetcode.com/problems/insert-interval
    //article https://leetcode.com/problems/insert-interval/discuss/3056773/C%2B%2B-extending-newInterval-O(N)
    //article https://leetcode.com/problems/insert-interval/discuss/3630023/C%2B%2B-One-Pass-O(N)-solution
    //article https://leetcode.com/problems/insert-interval/discuss/3630326/C%2B%2B-One-Pass-O(N)-or-easy-15-lines-with-explanation 
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int>& y = newInterval;
        vector<vector<int>> ans;        
        int i = 0, disjoint = -1;
        for(auto &x: intervals) {
            disjoint+=( (disjoint <0) && (x[1]>=y[0]));
            disjoint+=( (disjoint==0) && (y[1]<x[0]||y[0]>x[1]));
            if(disjoint==1) ans.push_back(y);
            disjoint+=  (disjoint >0);
            if(disjoint)
                ans.push_back(x);
            else 
                y = {min(x[0],y[0]), max(x[1],y[1])};
        }        
        if(disjoint <= 0) ans.push_back(y);
        return ans;
    }

    vector<vector<int>> insert_v06(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int>& y = newInterval;
        vector<vector<int>> ans;        
        int i = 0, disjoint = -1;
        for(auto &x: intervals) {
            if(disjoint == -1 && !(x[1]<y[0])) disjoint++; 
            if(!disjoint && (y[1]<x[0]||y[0]>x[1])) {
                ans.push_back(y);
                disjoint++;
            }
            if(disjoint)
                ans.push_back(x);
            else 
                y = {min(x[0],y[0]), max(x[1],y[1])};
        }        
        if(disjoint < 1) ans.push_back(y);
        return ans;
    }
    vector<vector<int>> insert_v05(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0], end = newInterval[1], n = intervals.size();
        vector<vector<int>> ans;        
        int i = 0, state = -1;
        for(auto &x: intervals) {
            if(state == -1 && !(x[1]<start)) state=0;
            if(state == 0 && (end<x[0] || start>x[1])) {
                ans.push_back({start, end});
                state=1;
            }
            if (!state) {
                start = min(x[0],start);
                end = max(x[1],end);                
            } else {
                ans.push_back(x);
            }            
        }        
        if(state < 1) ans.push_back({start, end});
        return ans;
    }

    vector<vector<int>> insert_v04(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0], end = newInterval[1], n = intervals.size();
        vector<vector<int>> ans;
        int i = 0, state = 0;
        while(i<n) {
            if(state == 0) {
                if(intervals[i][1]<start)
                    ans.push_back(intervals[i++]);
                else
                    state=1;
            } else if (state == 1) {
                auto &x = intervals[i];
                if(!(end<x[0] || start>x[1])) {
                    start = min(x[0],start);
                    end = max(x[1],end);
                    i++;
                } else {
                    ans.push_back({start, end});
                    state = 2;
                }
            } else {
                ans.push_back(intervals[i++]);
            }
        }
        if(state != 2) ans.push_back({start, end});
        return ans;
    }
    vector<vector<int>> insert_v03(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0], end = newInterval[1], n = intervals.size();
        vector<vector<int>> ans;        
        int i = 0;
        while(i<n && intervals[i][1]<start) ans.push_back(intervals[i++]); //add the x s.t. x < {start, end}
        while(i<n) {
            auto &x = intervals[i];
            if(end<x[0] || start > x[1]) break;
            start = min(x[0],start);
            end = max(x[1],end);
            i++;
        }
        ans.push_back({start, end});//add the largest union interval of newInterval
        while(i<n ) ans.push_back(intervals[i++]);//add the x s.t.{start, end} < x
        return ans;
    }
    vector<vector<int>> insert_v02(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0], end = newInterval[1], n = intervals.size();
        vector<vector<int>> ans;
        for(auto &x : intervals) {
            if(!(end<x[0]) && !(start > x[1])) {
                start = min(x[0],start);
                end = max(x[1],end);
            } 
        }
        int i = 0;
        while(i<n && intervals[i][1]<start) ans.push_back(intervals[i++]); //
        ans.push_back({start, end});//add the x s.t. x < {start, end}
        while(i<n && intervals[i][1]<=end) i++; //ignore when x belong to {start, end}
        while(i<n ) ans.push_back(intervals[i++]);//add the x s.t.{start, end} < x 
        return ans;
    }

    vector<vector<int>> inser_v01(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];
        for(int i = 0; i<n; i++) {
            if(intervals[i][0]<=start && start<=intervals[i][1]) 
                start = intervals[i][0];
            if(intervals[i][0]<=end && end<=intervals[i][1]) 
                end = intervals[i][1];
        }
        
        printf("{start,end} = %d,%d\n",start,end);
        int i = 0;
        for(i=0;i<n;i++) {
            vector<int> & inter =intervals[i];
            if(inter[1]<start) 
                ans.push_back(inter);
            else 
                break;
        }
        ans.push_back({start,end});
        for(;i<n;i++) {
            vector<int> & inter =intervals[i];
            if(inter[0]>end) {
                ans.push_back(inter);
            } 
        }
        
        
        return ans;
    }
};