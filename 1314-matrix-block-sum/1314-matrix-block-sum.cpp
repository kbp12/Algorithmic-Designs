class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>sum(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                sum[i][j] = mat[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //cout<<sum[i+1][j+1]<<" ";
                int u = max(0,i-k);
                int l = max(0,j-k);
                int b = min(m-1,i+k)+1;
                int r = min(n-1,j+k)+1;
                ans[i][j] = sum[b][r]+sum[u][l]-sum[b][l]-sum[u][r];
            }
            //cout<<endl;
        }
        return ans;
    }
};