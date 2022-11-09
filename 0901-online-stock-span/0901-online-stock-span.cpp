class StockSpanner {
public:
    vector<int>arr;
    stack<int>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int idx = arr.size() + 1;
        arr.push_back(price);
        while(st.size() and arr[st.top()-1]<=price) st.pop();
        int ans = idx;
        if(st.size()){
            ans =  idx - st.top();
        }
        st.push(idx);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */