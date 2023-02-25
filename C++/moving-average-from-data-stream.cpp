class MovingAverage {
    //https://leetcode.com/problems/moving-average-from-data-stream
    //article https://leetcode.com/problems/moving-average-from-data-stream/discuss/3227801/C%2B%2B-FIFO-queue-O(1)
public:
    typedef long long ll;
    ll sum=0,width=0;
    queue<ll> q;
    MovingAverage(int size) {
        width = size;
    }
    
    double next(int val) {
        if(q.size() == width) {
            sum -= q.front();
            q.pop();            
        }
        q.push(val);
        return (double)(sum+=val)/(double)(q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */