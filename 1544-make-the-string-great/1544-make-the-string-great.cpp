class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(st.size() and ((st.top()-'a') == (s[i]-'A') or (st.top()-'A') == (s[i]-'a'))) st.pop();
            else st.push(s[i]);
        }
        string ans = "";
        while(st.size()){
            ans+=st.top(); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};