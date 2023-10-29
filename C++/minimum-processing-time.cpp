class Solution {
    //https://leetcode.com/problems/minimum-processing-time/
    //article https://leetcode.com/problems/minimum-processing-time/discuss/4221132/Example-2-of-the-question-has-the-correct-answer-or-not
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        priority_queue<int> maxHeap; 
        priority_queue<int, vector<int>, greater<int>> minHeap; //process's core
        for(auto &p: processorTime) 
            for(int i = 0; i<4;i++)
                minHeap.push(p);
        
        for(auto &t:tasks)
            maxHeap.push(t);
        
        while(!maxHeap.empty()) {
            int maxt = maxHeap.top();
            maxHeap.pop();
            int minp = minHeap.top();
            minHeap.pop();
            minp += maxt;
            minHeap.push(minp);
        }
        
        int ans = 0;
        while(!minHeap.empty()) {
            ans = minHeap.top();
            minHeap.pop();
            printf("%d, ", ans);
        }
        return ans;

        
    }
};