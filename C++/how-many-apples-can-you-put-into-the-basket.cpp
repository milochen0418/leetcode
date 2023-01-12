class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        priority_queue<int, vector<int>, greater<int>> q;//maxQ
        for(auto &w:weight) q.push(w);
        int ans=0, total =0;
        while(!q.empty()) {
            int w = q.top(); q.pop();
            if(total+w>5000)break;            
            ans++;
            total+=w;            
        }
        return ans;
    }

    int maxNumberOfApples_sort(vector<int>& weight) {
        //Sorting 
        sort(weight.begin(), weight.end());
        int ans=0;
        int total = 0;
        for(auto &w: weight) {
            if(total+w <= 5000) {
                ans++;
                total+=w;
            } else {
                break;
            }
        }
        return ans;
    }
};