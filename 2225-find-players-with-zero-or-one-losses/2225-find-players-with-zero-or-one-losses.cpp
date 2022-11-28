class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        int n = a.size();
        vector<pair<int,int>>dp(100001);
        for(int i=0;i<100001;i++){
            dp[i].first = -1;
            dp[i].second = -1;
        }
        for(int i=0;i<n;i++){
            if(dp[a[i][0]].first==-1){
                dp[a[i][0]].first = 1;
            }else{
                dp[a[i][0]].first++;
            }
            
            if(dp[a[i][1]].second==-1){
                dp[a[i][1]].second = 1;
            }else{
                dp[a[i][1]].second++;
            }
        }
        
        vector<vector<int>>ans(2);
        for(int i=1;i<=100000;i++){
            if(dp[i].first !=-1 && dp[i].second==-1){
                ans[0].push_back(i);
            }
            
            if(dp[i].second == 1){
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};