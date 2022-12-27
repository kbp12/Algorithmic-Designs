class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        int n = c.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i] = c[i]-r[i];
        }
        sort(dp.begin(),dp.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==0){
                ans++;
            }else{
                if(a>=dp[i]){
                    a-=dp[i];
                    ans++;
                }else{
                    return ans;
                }
            }
        }
        return ans;
    }
};