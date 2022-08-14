class Solution {
public:
    string res;
    
    void backtrack(string &s, string &ans , vector<bool>& visit, int i, int n){
        if(i==n){
            res = min(res,ans);
            return;
        }
        for(auto ch='1';ch<='9';ch++){
            if(i==-1){
                visit[ch-'0'] = true;
                ans.push_back(ch);
                backtrack(s,ans,visit,i+1,n);
                visit[ch-'0'] = false;
                ans.pop_back();
            }else{
                if(s[i]=='I' and visit[ch-'0']==false and ans[i]<ch){
                    visit[ch-'0'] = true;
                    ans.push_back(ch);
                    backtrack(s,ans,visit,i+1,n);
                    visit[ch-'0'] = false;
                    ans.pop_back();
                }
                if(s[i]=='D' and visit[ch-'0']==false and ans[i]>ch){
                    visit[ch-'0'] = true;
                    ans.push_back(ch);
                    backtrack(s,ans,visit,i+1,n);
                    visit[ch-'0'] = false;
                    ans.pop_back();
                }
            }
        }
        return;
    }
    
    string smallestNumber(string s) {
        int n = s.size();
        res = "999999999";
        string ans = "";
        vector<bool>visit(10,false);
        backtrack(s,ans,visit,-1,n);
        return res;
    }
};