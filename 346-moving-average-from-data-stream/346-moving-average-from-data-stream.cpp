class MovingAverage {
public:
    int sz, count = 0;
    double sum = 0;
    queue<int>q;
    MovingAverage(int size) {
        sz = size;
    }
    
    double next(int val) {
        count++;
        sum+=val;
        q.push(val);
        if(count>sz){
            int f = q.front(); q.pop();
            sum-=f;
        }
        return sum/min(count,sz);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */