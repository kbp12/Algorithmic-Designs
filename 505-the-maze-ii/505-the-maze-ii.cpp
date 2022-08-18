class Solution {
public:
    void dfs(int i,int j,int a,int b, vector<vector<int>>& maze, vector<vector<int>>& dist, int n, int m, int len){
        if(dist[i][j]<=len) return;
        dist[i][j] = len;
        if(i==a and j==b) return;
        int l = j, r = j, u = i, d = i;
        while(l>0 and maze[i][l-1]!=1){
            l--;
        }
        if(abs(l-j)) dfs(i,l,a,b,maze,dist,n,m,len+abs(l-j));
        while(u>0 and maze[u-1][j]!=1){
            u--;
        }
        if(abs(u-i)) dfs(u,j,a,b,maze,dist,n,m,len+abs(i-u));
        while(r<m-1 and maze[i][r+1]!=1){
            r++;
        }
        if(abs(j-r)) dfs(i,r,a,b,maze,dist,n,m,len+abs(j-r));
        while(d<n-1 and maze[d+1][j]!=1){
            d++;
        }
        if(abs(d-i)) dfs(d,j,a,b,maze,dist,n,m,len+abs(i-d));
        return;
    }
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dfs(start[0],start[1],destination[0],destination[1],maze,dist,n,m,0);
        return dist[destination[0]][destination[1]]==INT_MAX?-1:dist[destination[0]][destination[1]];
    }
};