class Solution {
public:
    int maxProduct(vector<string>& w) {
        int n = w.size();
        vector<vector<bool>>dp(n,vector<bool>(26,false));
        for(int i=0;i<n;i++){
            int m = w[i].length();
            for(int j=0;j<m;j++){
                dp[i][w[i][j]-'a'] = true;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool temp = true;
                for(int k=0;k<26;k++){
                    if(dp[i][k] && dp[j][k]){
                        temp = false;
                        break;
                    }
                }
                if(temp){
                    int a = w[i].length();
                    int b = w[j].length();
                    ans = max(ans,a*b);
                }
            }
        }
        return ans;
    }
};