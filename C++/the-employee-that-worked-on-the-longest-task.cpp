class Solution {
    //https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        /*   
        printf("(1)logs = {");
        for(int i = 0; i<logs.size();i++) {
            printf("[%d, %d], ", logs[i][0], logs[i][1]);
        }
        printf("};\n");
        */
        for(int i = 0; i < logs.size();i++) {
            int start_time = i==0?0:logs[i-1][1];
            int leave_time = logs[i][1];
            logs[i].push_back(leave_time - start_time); //logs[i][2] become units of time here
        }
        /*
        printf("(2)logs = {");
        for(int i = 0; i<logs.size();i++) {
            printf("[%d, %d, %d], ", logs[i][0], logs[i][1], logs[i][2]);
        }
        printf("};\n");
        */
        sort(logs.begin(), logs.end(), [](auto& lhs, auto& rhs) {
            if(lhs[2] == rhs[2]) {
                return lhs[0] < rhs[0];
            } else {
                return lhs[2] > rhs[2];
            }
        });
        /*
        printf("(3)logs = {");
        for(int i = 0; i<logs.size();i++) {
            printf("[%d, %d, %d], ", logs[i][0], logs[i][1], logs[i][2]);
        }
        printf("};\n");
        */
        return logs[0][0];
        
    }
};