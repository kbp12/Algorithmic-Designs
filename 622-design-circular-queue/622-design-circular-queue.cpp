class MyCircularQueue {
public:
    int n;
    deque<int>dq;
    MyCircularQueue(int k) {
        n = k;
        return;
    }
    
    bool enQueue(int value) {
        if(dq.size()<n){
            dq.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(dq.size()){
            dq.pop_front();
            return true;
        }
        return false;
    }
    
    int Front() {
        if(dq.size()) return dq.front();
        return -1;
    }
    
    int Rear() {
        if(dq.size()) return dq.back();
        return -1;
    }
    
    bool isEmpty() {
        return !dq.size();
    }
    
    bool isFull() {
        return dq.size()==n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */