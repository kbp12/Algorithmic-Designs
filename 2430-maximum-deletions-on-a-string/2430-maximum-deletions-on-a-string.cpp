class Solution {
public:
    int n;
    int dp[4005];
    int f(string_view s, int l){
        if (l== n-1){
            return 1;
        }
        if(dp[l]!=-1) return dp[l];
        int cnt = 1;
        string str = "";
        int ans = 1;
        for (int i = l; i < n; i++) {
            str.push_back(s[i]);
            string_view s2 =s.substr(i + 1, str.size());
            if (s2 == str) {
                cnt = 1 + f(s,i+1);
                ans = max(ans,cnt);
            }
        }
        return dp[l] = ans;
    }
    int deleteString(string s) {
        n = s.size();
        memset(dp,-1,sizeof dp);
        //vector<vector<int>> ref(n,vector<int>(n,0));
        
        string_view s1{s};
        return f(s1,0);
    }

};