class MinStack {
public:
    stack<int>st, minst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.size()==0 or minst.top()>=val){
            minst.push(val);
        }
        return;
    }
    
    void pop() {
        if(minst.size() and minst.top() == st.top()) minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if(minst.size()) return minst.top();
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */