class Solution {
public:
    vector<int> dir = { 0, 1, 0, -1, 0 }; 
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int pi, int pj){
        visited[i][j] = true;
        for(int k = 0; k < 4; k++){
            int dx = i+dir[k];
            int dy = j+dir[k+1];
            if(dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[0].size() && grid[dx][dy] == grid[i][j] && (pi == dx && pj == dy)==false){
                if(visited[dx][dy]) return true;
                if(dfs(grid, visited, dx,dy,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j]==false && dfs(grid, visited, i, j, -1, -1)){
                    return true;
                }
            }
        }
        return false;
    }
};