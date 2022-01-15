class Solution {
    //https://leetcode.com/problems/jump-game-iv/submissions/
public:
    int minJumps(vector<int>& arr) {
        
        
        unordered_multimap<int,int> mmap;
        
        
        for(int i = 0; i < arr.size(); i++) {
            mmap.insert({arr[i],i});
        }
        
    
    
        int end = arr.size() - 1;
        vector<bool> visited(arr.size(), false);
        vector<int> lens(arr.size(), 0);
        queue<int> q; 
        visited[0] = true;
        lens[0] = 0;
        q.push(0);
        
        
        
        
        
        while(!q.empty()) {
            int i = q.front();            
            q.pop();
            
            if(i == end) {
               return lens[i]; 
            }
            
            if( i+1 < arr.size()) {
                int candidate = i + 1;
                if(visited[candidate] == false) {
                    visited[candidate] = true;
                    lens[candidate] = lens[i] + 1;
                    q.push(candidate);
                }
            } 
            if( i-1 >= 0) {
                int candidate = i - 1;
                if(visited[candidate] == false) {
                    visited[candidate] = true;
                    lens[candidate] = lens[i] + 1;
                    q.push(candidate);                    
                }                
            }
            
            auto p = mmap.equal_range(arr[i]);
            for (auto it = p.first; it != p.second; ++it) {
                //std::cout << " " << it->first << ":" << it->second;
                int j = it->second;
                if(i!=j ) {
                    int candidate = j;
                    if(visited[candidate] == false) {
                        visited[candidate] = true;
                        lens[candidate] = lens[i] + 1;
                        q.push(candidate);                    
                    }
                }
            }
        }
        return 0;
    }
};