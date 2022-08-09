class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n =  arr.size();
        vector<long long>dp(n,0);
        int mod = 1e9+7;
        set<int>s;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 and s.find(arr[i]/arr[j])!=s.end()){
                    int ele = arr[i]/arr[j];
                    dp[i] = (dp[i]+(dp[j]*dp[mpp[ele]])%mod)%mod;
                }
            }
            s.insert(arr[i]);
            mpp[arr[i]] = i;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans+dp[i])%mod;
        }
        return ans;
    }
};