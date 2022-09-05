class Solution {
public:
    vector<int>dx = {1,0,1,-1};
    vector<int>dy = {0,1,1,1};
    int search(vector<vector<int>>grid, int k){
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int a = i-dy[k], b = j-dx[k];
                    if(a>=0 and b>=0 and a<n and b<m){
                        grid[i][j]+=grid[a][b];
                    }
                    ans = max(ans,grid[i][j]);
                }
            }
        }
        return ans;
    }
    
    int longestLine(vector<vector<int>>& mat) {
        int ans = 0;
        for(int k=0;k<4;k++){
            int res = search(mat,k);
            ans = max(ans,res);
        }
        return ans;
    }
};