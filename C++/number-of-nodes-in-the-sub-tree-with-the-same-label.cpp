class Solution {
    //https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
    //article https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/discuss/3038318/C%2B%2B-DFS-explanation
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/6032768313412276/
public:
    
    unordered_map<int, vector<int>> mp;//mapping vertex to its neighborhoods
    vector<int> count; //count number for each node according to the condition of same label.
    unordered_map<int, vector<int>> stks; 
    //the same label's stack for DFS to trace their same label parent(closest ancestor with same label)
    
    vector<bool> visited;//for DFS algorithm to check travel status
    string labels;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labelss) {
        count = vector<int>(n,0);
        labels = labelss;
        visited = vector<bool>(n,false);
        for(auto &e: edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        new_dfs(0);
        return count;
    }
    
    
    void new_dfs(int root) {
        visited[root] = true;
        count[root] = 1;
        
        //get the closest ancestor of root with same label
        int parent_node = -1;
        if(!stks[labels[root]-'a'].empty()) 
            parent_node = stks[labels[root]-'a'].back();
        
        stks[labels[root]-'a'].push_back(root);        
        for(auto &child: mp[root]) 
            if(visited[child] == false) 
                new_dfs(child);
        stks[labels[root]-'a'].pop_back();
        
        if(parent_node>=0) 
            count[parent_node] = count[parent_node] + count[root];
    }


    vector<vector<int>> extend;
    vector<int> countSubTrees_v01(int n, vector<vector<int>>& edges, string labelss) {
        labels = labelss;
        extend=vector<vector<int>>(n,vector<int>(26,0));
        visited = vector<bool>(n,false);
        for(auto &e: edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        dfs(0);
        vector<int> ans = vector<int>(n,0);
        for(int i = 0; i<n;i++)  ans[i] = extend[i][labels[i]-'a'];
        return ans;
    }

    void dfs(int root) {
        visited[root] = true;
        extend[root][labels[root]-'a']++;
        for(auto &child: mp[root]) {
            if(visited[child] == false) {
                dfs(child);
                for(int i = 0;i<26;i++) extend[root][i]+=extend[child][i];
            }
        }
    }
};