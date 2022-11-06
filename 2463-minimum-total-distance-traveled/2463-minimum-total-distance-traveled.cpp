class Solution {
public:
    long long dp[105][105][105];
    int n,m;
    long long dfs(int i, int j, int k, vector<int>& robot, vector<vector<int>>& factory){
        if(i==n) return 0;
        if(j==m) return 1e18;
        if(dp[i][j][k]) return dp[i][j][k];
        long long ans = 1e18;
        if(k<factory[j][1]){
            long long t = dfs(i+1,j,k+1,robot,factory);
            if(t!=1e18)
                ans = abs(robot[i] - factory[j][0]) + t;
        }
        long long temp = dfs(i,j+1,0,robot,factory);
        ans = min(ans , temp);
        return dp[i][j][k] = ans;
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin() , robot.end());
        sort(factory.begin() , factory.end());
        n = robot.size();
        m = factory.size();
        return dfs(0,0,0,robot,factory);
    }
};