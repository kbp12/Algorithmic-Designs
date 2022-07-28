class Solution {
public:
    int maxRepeating(string s, string w) {
        int n = s.length(), m = w.length();
        vector<int>idx;
        set<int>sett;
        for(int i=0;i<n;i++){
            int j = 0;
            for(;j<m and i+j<n;j++){
                if(s[i+j]==w[j]){
                    
                }else{
                    break;
                }
            }
            if(j==m){
                idx.push_back(i);
                sett.insert(i);
            }
        }
        int cur = 0, ans = 0;
        for(int i=0;i<idx.size();i++){
            int a = idx[i];
            cur = 1;
            while(sett.find(a+m)!=sett.end()){
                a+=m;
                cur++;
            }
            ans = max(ans,cur);
        }
        return ans;
    }
};