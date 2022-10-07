class MyCalendarThree {
public:
    vector<int>st;
    vector<int>en;
    MyCalendarThree() {
        return;
    }
    
    int book(int s, int e) {
        st.push_back(s);
        en.push_back(e);
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());
        int c = 0, i = 0, j = 0, ans = 0;
        while(i<st.size()){
            if(st[i]<en[j]){
                c++; i++;
            }
            else{
                c--; j++;
            }
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