class Solution {
public:
    bool comp(int i1, int i2, int l, vector<vector<int>>& match, string & s){
        int sz = match[i1][i2];
        if(sz>=l) return true;
        if(s[i1+sz] <= s[i2+sz]) return true;
        return false;
    }
    
    int numberOfCombinations(string s) {
        // base case
        if(s[0] == '0') return 0;
        
        int n = s.size() , mod = 1e9+7;
        // to know the longesst common match between two strings starting at two positions say i,j
        vector<vector<int>>match(n+1 , vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[i] == s[j]){
                    match[i][j] = 1+match[i+1][j+1];
                }
            }
        }
        
        // 
        vector<vector<int>>pref_dp(n,vector<int>(n,0));
        // base case is there is always 1 number starting from 0 and ending at j
        for(int j=0;j<n;j++) pref_dp[0][j] = 1;
        
        for(int i=1;i<n;i++){
            // case that no new number can start with i
            if(s[i] == '0'){
                pref_dp[i] = pref_dp[i-1];
                continue;
            }
            for(int j=i;j<n;j++){
                int len = j-i+1, prev_start = i-1-(len-1) , count = 0;
                if(prev_start<0){
                    count = pref_dp[i-1][i-1]; // stores all the values of dp starting at 0 to i-1 and ending at i-1
                }
                else{
                    count = (pref_dp[i-1][i-1] - pref_dp[prev_start][i-1] + mod)%mod;
                    if(comp(prev_start , i, len, match, s)){
                        int cnt = 0;
                        if(prev_start == 0){
                            cnt = pref_dp[0][i-1];
                        }else{
                            cnt = (pref_dp[prev_start][i-1] - pref_dp[prev_start - 1][i-1] + mod) %mod;
                        }
                        count = (count + cnt )%mod;
                    }
                }
                pref_dp[i][j] = (pref_dp[i-1][j] + count) %mod;
            }
        }
        return pref_dp[n-1][n-1];
    }
};