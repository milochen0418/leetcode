
class Solution {
    //https://leetcode.com/problems/jump-game-iv
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
            
            if( i+1 < arr.size() && visited[i+1] == false) {
                visited[i+1] = true;
                lens[i+1] = lens[i] + 1;
                q.push(i+1);
            } 
            if( i-1 >= 0 && visited[i-1] == false) {
                visited[i-1] = true;
                lens[i-1] = lens[i] + 1;
                q.push(i-1);                    
            }
            
            if(mmap.find(arr[i]) != mmap.end()) {
                auto p = mmap.equal_range(arr[i]);
                for (auto it = p.first; it != p.second; ++it) {
                    int j = it->second;
                    if(i!=j && visited[j] == false) {
                        visited[j] = true;
                        lens[j] = lens[i] + 1;
                        q.push(j);
                    }
                }
                mmap.erase(arr[i]); 
                //It can avoid redundant processing case, like this
                //[7,7,7,7,....7,11]
            }           
        }
        return 0;
    }
};
