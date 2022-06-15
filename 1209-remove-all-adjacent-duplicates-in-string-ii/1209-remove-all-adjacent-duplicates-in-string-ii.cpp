class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            if(st.size()){
                char c = st.top().first;
                int v = st.top().second;
                if(s[i]==c){
                    if(v==k-1){
                        int j = 1;
                        while(j<k){
                            st.pop(); j++;
                        }
                    }else{
                        st.push({s[i],v+1});
                    }
                }else{
                    st.push({s[i],1});
                }
            }else{
                st.push({s[i],1});
            }
        }
        string ans = "";
        while(st.size()){
            ans+=st.top().first; st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};