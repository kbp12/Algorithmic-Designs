class Solution {
public:
    int n;
    int dp[4005] = {};
    int f(string_view s, int l){
        if (l== n-1){
            return 1;
        }
        if(dp[l]) return dp[l];
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
        string_view s1{s};
        return f(s1,0);
    }

};