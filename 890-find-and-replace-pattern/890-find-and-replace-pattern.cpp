class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string>ans;
        int n = p.size();
        for(auto w:words){
            map<char,char>mpp;
            set<char>st;
            bool add = true;
            for(int i=0;i<n;i++){
                if(mpp.find(p[i])!=mpp.end()){
                    if(w[i]==mpp[p[i]]){
                        
                    }else{
                        add = false; break;
                    }
                }else{
                    if(st.find(w[i])!=st.end()){
                        add = false;
                        break;
                    }else{
                        st.insert(w[i]);
                        mpp[p[i]] = w[i];
                    }
                }
            }
            if(add){
                ans.push_back(w);
            }
        }
        return ans;
    }
};