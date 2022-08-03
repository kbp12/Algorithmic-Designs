class MyCalendar {
public:
    map<int,int>events;
    MyCalendar() {
        
    }
    
    bool book(int st, int end) {
        auto next = events.upper_bound(st);
        if(next != events.end() &&   (*next).second < end) return false;
        events.insert({end,st});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */