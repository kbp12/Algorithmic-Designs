class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                if(st.size() && s[st.top()]=='(') st.pop();
                else st.push(i);
            }
        }
        int ans = 0;
        int a = n;
        if(st.size()){
            a = st.top()+1; st.pop();
            ans = n-a;
        }else
            return n;
        while(st.size()){
            int b = st.top()+1; st.pop();
            ans = max(ans,a-b-1);
            a = b;
        }
        ans = max(ans,a-1);
        return ans;
    }
};