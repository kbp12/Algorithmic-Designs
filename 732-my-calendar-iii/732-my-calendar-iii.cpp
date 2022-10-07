class MyCalendarThree {
public:
    map<int,int>mpp;
    MyCalendarThree() {
        return;
    }
    
    int book(int start, int end) {
        mpp[start]++;
        mpp[end]--;
        int ans = 0, c = 0;
        for(auto it:mpp){
            c+=it.second;
            ans = max(ans,c);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */