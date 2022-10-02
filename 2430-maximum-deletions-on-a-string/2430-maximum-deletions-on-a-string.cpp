class Solution {
public:
    int dp[4005] = {};
    int helper(string s){
        int siz = s.size();
        if(siz==0) return 0;
        if(dp[siz]) return dp[siz];
        vector<int> prefix = z(s);
        bool check = false;
        int ans = 0;
        for(int j = 1 ; j < siz ; j++){
            int val = (j+1)/2;
            if(j%2==1 and prefix[j] == val){
                check = true;
                ans = max(ans,1+helper(s.substr(prefix[j])));
            }
        }
        if(check==false){
            return 1;
        }
        return dp[siz] = ans;
    }
    
    vector<int> z(string s){
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    
    int deleteString(string s) {
        return helper(s);
    }
};