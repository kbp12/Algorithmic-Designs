class Solution {
public:
    bool hasValidPath(vector<vector<char>>& A) {
        int m = A.size(), n = A[0].size(), maxk = (m + n + 1) / 2;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxk + 10)));
        dp[0][0][1] = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 1; k <= maxk; ++k) {
                    dp[i][j + 1][k] |= dp[i][j][k + (A[i][j] == '(' ? -1 : 1)];
                    dp[i + 1][j][k] |= dp[i][j][k + (A[i][j] == '(' ? -1 : 1)];
                }
        return dp[m][n - 1][1]; 
    }
};