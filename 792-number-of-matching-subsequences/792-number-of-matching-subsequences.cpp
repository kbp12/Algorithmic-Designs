class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<pair<int,int>>dp[26];
        int i=0;
        for(auto word:words){
            dp[word[0]-'a'].push_back({i,0});
            i++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            auto it = dp[ch-'a'];
            dp[ch-'a'].clear();
            for(auto e:it){
                int sz = words[e.first].size();
                int idx = e.second;
                if(idx==sz-1){
                    ans++;
                }else{
                    idx++;
                    int j = words[e.first][idx]-'a';
                    dp[j].push_back({e.first,idx});
                }
            }
        }
        return ans;
    }
};