class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long long>st;
        for(int i=0;i<n;i++){
            if(tokens[i] == "-"){
                long long val1 = st.top(); st.pop();
                long long val2 = st.top(); st.pop();
                val2-=val1;
                st.push(val2);
            }else if(tokens[i] == "+"){
                long long val1 = st.top(); st.pop();
                long long val2 = st.top(); st.pop();
                val1+=val2;
                st.push(val1);
            }else if(tokens[i] == "/"){
                long long val1 = st.top(); st.pop();
                long long val2 = st.top(); st.pop();
                val1=val2/val1;
                st.push(val1);
            }else if(tokens[i] == "*"){
                long long val1 = st.top(); st.pop();
                long long val2 = st.top(); st.pop();
                val1*=val2;
                st.push(val1);
            }else{
                int val = stoi(tokens[i]);
                st.push(val);
            }
        }
        return st.top();
    }
};