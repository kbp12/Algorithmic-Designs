class Solution {
public:
    int dis(vector<vector<int>>& matrix, int i,int j, int m, int n,vector<vector<int>>& dp){
        if(dp[i][j]) return dp[i][j];
        int a=1,b=1,c=1,d=1;
        if(i>0 && matrix[i-1][j]>matrix[i][j])
            a+=dis(matrix,i-1,j,m,n,dp);
        if(j>0 && matrix[i][j-1]>matrix[i][j])
            b+=dis(matrix,i,j-1,m,n,dp);
        if(i<m-1 && matrix[i+1][j]>matrix[i][j])
            c+=dis(matrix,i+1,j,m,n,dp);
        if(j<n-1 && matrix[i][j+1]>matrix[i][j])
            d+=dis(matrix,i,j+1,m,n,dp);
        
        dp[i][j] = max(a,max(b,max(c,d)));
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int c = 0;
        int ans = 0;
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                c = dis(matrix,i,j,m,n,dp);
                if(c>ans) ans = c;
            }
        }
        return ans;
    }
};