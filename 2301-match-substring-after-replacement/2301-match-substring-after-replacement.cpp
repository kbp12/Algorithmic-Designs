class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mapp) { 
        int m = s.length();
        int n = sub.length();
        int k = mapp.size();
        unordered_map<char,set<char>>u;
        for(int i=0;i<k;i++){
            u[mapp[i][0]].insert(mapp[i][1]);
        }
        for(int i=0;i<=m-n;i++){
            bool ok = true;
            for(int j=0;j<n;j++){
                char c = s[i+j], d = sub[j];
                if(c==d){
                    
                }else if(u[d].find(c)!=u[d].end()){
                    
                }else{
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
        return false;
    }
};