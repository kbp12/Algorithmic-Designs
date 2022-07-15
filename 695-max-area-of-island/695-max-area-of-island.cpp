class Solution {
public:
    bool isPieceOfLand(int i,int j,int m,int n,vector<vector<int>>&grid){
        return i>=0 && j>=0 && i<m && j<n && grid[i][j]==1;
    }
    
    int bfs(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(isPieceOfLand(i,j,m,n,grid)==false) return 0;
        int area = 1;
        grid[i][j] = 0;
        area+=bfs(i+1,j,m,n,grid);
        area+=bfs(i-1,j,m,n,grid);
        area+=bfs(i,j+1,m,n,grid);
        area+=bfs(i,j-1,m,n,grid);
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int curr_area = bfs(i,j,m,n,grid);
                    max_area = max(max_area,curr_area);
                }
            }
        }
        return max_area;
    }
};