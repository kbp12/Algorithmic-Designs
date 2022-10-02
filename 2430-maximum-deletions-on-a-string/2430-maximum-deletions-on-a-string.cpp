class Solution {
public:
    int dp[4005] = {};
    int find(string s){
        int siz = s.size();
        if(siz==0) return 0;
        if(dp[siz]) return dp[siz];
        auto z_arr = z_f(s);
        int ans = 1;
        for(int i=1;i<siz;i+=2){
            if(z_arr[i] == (i+1)/2){
                ans = max(ans,1+find(s.substr(z_arr[i])));
            }
        }
        return dp[siz] = ans;
    }
    
    vector<int> z_f(string s){
        int n = s.size();
        vector<int> dp(n,0);
        for (int i=1;i<n;i++) {
            int j = dp[i-1];
            while(j>0 and s[i]!=s[j])
                j = dp[j-1];
            if (s[i]==s[j])
                j++;
            dp[i] = j;
        }
        return dp;
    }
    
    int deleteString(string s) {
        return find(s);
    }
};