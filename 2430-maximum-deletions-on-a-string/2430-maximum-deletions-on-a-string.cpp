class Solution {
public:
    int dp[4005] = {};
    int helper(string s){
        int siz = s.size();
        if(siz==0) return 0;
        if(dp[siz]) return dp[siz];
        vector<int> z_arr = z_f(s);
        int ans = 0;
        bool found = true;
        for(int i=1;i<siz;i++){
            if(i%2==1 and z_arr[i] == (i+1)/2){
                found = false;
                ans = max(ans,1+helper(s.substr(z_arr[i])));
            }
        }
        if(found){
            return 1;
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
        return helper(s);
    }
};