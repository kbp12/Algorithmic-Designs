class SeatManager {
public:
    set<int>s;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            s.insert(i);
        }
        return;
    }
    
    int reserve() {
        int f = *s.begin();
        s.erase(f);
        return f;
    }
    
    void unreserve(int sn) {
        s.insert(sn);
        return;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */