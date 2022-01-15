class Solution {
    //https://leetcode.com/problems/jump-game-iv
public:
    int someone(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        
        unordered_map<int, vector<int>> mp;
        
        int step = 0;
        
        //fill map
        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        
        //queue
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            step++;
            int size = q.size();
            
            for(int i = 0; i<size; i++){
                int j = q.front();
                q.pop();
                
                //jump to j-1
                if(j-1 >= 0 && mp.find(arr[j-1]) != mp.end()){
                //if(j-1 >= 0 ){                
                    q.push(j-1);
                }
                
                //jump to j+1
                if(j+1 < n && mp.find(arr[j+1]) != mp.end()){
                //if(j+1 < n){
                    if(j+1 == n-1) return step;
                    q.push(j+1);
                }
                
                // jump to equal
                if(mp.find(arr[j]) != mp.end()){
                    for(auto k: mp[arr[j]]){
                        if(k != j){
                            if(k == n-1) return step;
                            q.push(k);
                        }
                    }
                }
                mp.erase(arr[j]);
            }
        }
        return step;        
    }
    int minJumps(vector<int>& arr) {
        
        return someone(arr);
        //unordered_multimap<int,int> mmap;
        unordered_multimap<int,int> mmap;
        unordered_map<int, vector<int>> vmap;
        
        
        for(int i = 0; i < arr.size(); i++) {
            mmap.insert({arr[i],i});
            vmap[arr[i]].push_back(i);
        }
        
    
    
        int end = arr.size() - 1;
        vector<bool> visited(arr.size(), false);
        vector<int> lens(arr.size(), 0);
        queue<int> q; 
        visited[end] = true;
        lens[end] = 0;
        q.push(end);
        
        
        
        
        
        while(!q.empty()) {
            int i = q.front();            
            q.pop();
            
            if(i == 0) {
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
            
            /*
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
            }*/
            auto v = vmap[arr[i]];
            for(auto j:v) {
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