class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides){
        int siz = rides.size();
        sort(rides.begin(),rides.end(),
             [](vector<int>&ride1, vector<int>&ride2){
                    return ride1[1]<ride2[1];
        });
        vector<long long>dp(n+1,0);
        int i=0;
        for(int point=1;point<=n;point++){
            if(i<siz && point == rides[i][1]){
                while(i<siz && point == rides[i][1]){
                    dp[point] = max(dp[point],dp[rides[i][0]]+rides[i][2]+rides[i][1]-rides[i][0]);
                    i++;
                }
            }
            dp[point] = max(dp[point],dp[point-1]);
        }
        return dp[n];
    }
};