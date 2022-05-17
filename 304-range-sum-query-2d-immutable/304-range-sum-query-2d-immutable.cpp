class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int m =  matrix.size();
        int n = matrix[0].size();
        vector<int>v(n+1,0);
        dp.push_back(v);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                v[j] = matrix[i-1][j-1]+v[j-1]+dp[i-1][j]-dp[i-1][j-1];
            }
            dp.push_back(v);
        } 
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        r2++; c2++;
        return dp[r2][c2]-dp[r1][c2]-dp[r2][c1]+dp[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */