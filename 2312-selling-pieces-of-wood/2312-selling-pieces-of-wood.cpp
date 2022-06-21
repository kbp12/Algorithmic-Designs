class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        long long dp[201][201] = {};
        for(auto price:prices){
            dp[price[0]][price[1]] = price[2];
        }
        for(int row = 1; row <= m ; row++){
            for(int col = 1; col <= n ; col++){
                for(int cut_at = 1; cut_at<=(col/2); cut_at++){
                    dp[row][col] = max(dp[row][col],dp[row][cut_at]+dp[row][col-cut_at]);
                }
                for(int cut_at = 1; cut_at<=(row/2); cut_at++){
                    dp[row][col] = max(dp[row][col],dp[cut_at][col]+dp[row-cut_at][col]);
                }
            }
        }
        return dp[m][n];
    }
};