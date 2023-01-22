class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<bool>>dp;
    string s;
    void solve(int i, int n, vector<string>temp){
        if(i==n+1){
            ans.push_back(temp);
            return;
        }
        if(i==n){
            temp.push_back(s.substr(i,1));
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<=n;j++){
            if(dp[i][j]){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,n,temp);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string str) {
        s = str;
        int n = s.length();
        dp = vector<vector<bool>>(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
            if(i!=n-1 && s[i]==s[i+1])
                dp[i][i+1] = true;
        }
        for(int l = 2;l<n;l++){
            for(int i=0;i<n-l;i++){
                if(s[i]==s[i+l] && dp[i+1][i+l-1]){
                    dp[i][i+l] = true;
                }
            }
        }
        vector<string>temp;
        solve(0,n-1,temp);
        return ans;
    }
};