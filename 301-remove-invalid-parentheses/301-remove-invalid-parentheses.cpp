class Solution {
public:
    void dfs(string s,int idx,int l, int r,int pair,string path,set<string>&strs){
        if(l+r>s.size()-idx)
            return;
        if(idx == s.size()){
            if(l== 0 && r== 0 && pair==0){
                strs.insert(path);
            }
            return;
        }
        if(s[idx]!='(' && s[idx]!=')'){
            dfs(s,idx+1,l,r,pair,path+s[idx],strs);
        }
        else {
            if(s[idx]=='(') {
                if(l>0){
                    dfs(s,idx+1,l-1,r,pair,path,strs);
                }
                dfs(s,idx+1,l,r,pair+1,path+s[idx],strs);
            }
            if(s[idx]==')'){
                if(r>0){
                    dfs(s,idx+1,l,r-1,pair,path,strs);
                }
                if(pair>0) {
                    dfs(s,idx+1,l,r,pair-1,path+s[idx],strs);
                }
            }
        }
        return;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        set<string> strs;
        int l = 0;
        int r = 0;
        for(auto ch:s) {
            if(ch == '(') {
                l++;
            }
            if(ch == ')') {
                if(l!= 0) {
                    l--;
                }
                else {
                    r++;
                }
            }
        }
        dfs(s,0,l,r,0,"",strs);
        return vector<string>(strs.begin(),strs.end());
    }
};