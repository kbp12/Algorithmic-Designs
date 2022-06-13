class Solution {
public:
    long long countVowels(string w) {
        int n = w.size();
        vector<long long>dp(n+1,0);
        long long ans = 0;
        for(int i=1;i<=n;i++){
            char c = w[i-1];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                dp[i] = dp[i-1]+i;
            }else{
                dp[i] = dp[i-1];
            }
            ans+=dp[i];
        }
        return ans;
    }
};