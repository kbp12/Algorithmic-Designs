class Solution {
public:
    bool bfs(int i, int j, int a, int b, vector<vector<int>>& maze, vector<vector<bool>>& visited, int n, int m){
        if(i==a and j==b) return true;
        visited[i][j] = true;
        int ii = i;
        while(ii>0 and maze[ii-1][j]!=1){
            ii--;
        }
        if(!visited[ii][j] and bfs(ii,j,a,b,maze,visited,n,m)) return true;
        ii = i;
        while(ii<n-1 and maze[ii+1][j]!=1){
            ii++;
        }
        if(!visited[ii][j] and bfs(ii,j,a,b,maze,visited,n,m)) return true;
        int jj = j;
        while(jj>0 and maze[i][jj-1]!=1){
            jj--;
        }
        if(!visited[i][jj] and bfs(i,jj,a,b,maze,visited,n,m)) return true;
        jj =j;
        while(jj<m-1 and maze[i][jj+1]!=1){
            jj++;
        }
        if(!visited[i][jj] and bfs(i,jj,a,b,maze,visited,n,m)) return true;
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        return bfs(start[0],start[1],destination[0],destination[1],maze,visited,n,m);
    }
};