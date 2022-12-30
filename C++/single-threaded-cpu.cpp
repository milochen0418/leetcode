class Solution {
public:
    //function<vector<int>(vector<int>)
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0 ; i<tasks.size();i++) {
            tasks[i].push_back(i); //original task index is in task[2]
        }
        sort(tasks.begin(), tasks.end(),[](auto&lhs, auto&rhs){
            if(lhs[0]==rhs[0])
                return lhs[2]<rhs[2];
            else
                return lhs[0]<rhs[0];
        });
        printf("sorted tasks = ");
        for(auto &t:tasks)printf("[%d,%d,%d], ", t[0],t[1],t[2]);
        printf("\n");
        function<bool(vector<int>&, vector<int>&)> comp = [&]( vector<int>& lhs, vector<int>& rhs) { 
            if(lhs[1] == rhs[1]) 
                return lhs[2] > rhs[2];
            else 
                return lhs[1] > rhs[1];
        };
        
        vector<int> ans;
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minQ(comp);
        
        int curr_time_idx = 0;
        long long curr_time = tasks[curr_time_idx][0];
        do {

            while(curr_time_idx<tasks.size() && tasks[curr_time_idx][0]<=curr_time)  {
                printf("minQ.push(tasks[curr_time_idx=%d]) as curr_time = %d\n", curr_time_idx, curr_time);
                minQ.push(tasks[curr_time_idx++]);
            }
            if(minQ.empty() && curr_time_idx<tasks.size()) {
                curr_time=tasks[curr_time_idx][0];
                printf("minQ.push(tasks[curr_time_idx=%d]) as curr_time = %d\n", curr_time_idx, curr_time);
                minQ.push(tasks[curr_time_idx++]);
            }
            if(!minQ.empty()) {
                vector<int> task = minQ.top();
                printf("minQ.pop task=(%d,%d,%d)\n", task[0],task[1],task[2]);
                minQ.pop();
                ans.push_back(task[2]);
                curr_time += task[1];
                printf("curr_time = %d\n", curr_time);
            }
        } while(!minQ.empty() || curr_time_idx<tasks.size());
        
        return ans;            
    }
};

/*
Error Case
[[5,2],[7,2],[9,4],[6,3],[5,10],[1,1]]
[5,0,4,1,3,2] Output
[5,0,1,3,2,4] Expected
... Solve

[[5,6],[9,4],[3,9],[3,7],[1,1],[6,9],[9,1]]
[4,2,6,1,0,3,5] Output
[4,3,6,1,0,2,5] Expected
*/