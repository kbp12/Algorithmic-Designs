class cluster
{
    public:
        set<pair<int,int>> c; 
        set<pair<int,int>> uc;
        int walls = 0; 
};

struct cmp{
    bool operator()(cluster &a, cluster &b){
        return a.uc.size()<b.uc.size();
    }  
};
      

class Solution {
public:
    
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis, cluster &clust){
        if(i>=grid.size() or i<0 or j<0 or j>=grid[0].size() or vis[i][j] or grid[i][j] == -1)  return;
        if(grid[i][j] == 0){
            clust.walls++;
            clust.uc.insert({i,j});
            return;
        }
        clust.c.insert({i,j});
        vis[i][j] = true;
        dfs(grid,i+1,j,vis,clust);
        dfs(grid,i-1,j,vis,clust);
        dfs(grid,i,j+1,vis,clust);
        dfs(grid,i,j-1,vis,clust);
        return;
    }

    int containVirus(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        while(true){
            vector<vector<bool>> vis(n,vector<bool>(m));
            // auto comp=[](const cluster& A,const cluster& B)
            // { 
            //     return A.uc.size()<B.uc.size();
            // };
            priority_queue<cluster,vector<cluster>, cmp> pq;
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        cluster c;
                        dfs(grid,i,j,vis,c);
                        pq.push(c);
                    }
                }
            }
            if(pq.size()==0)    break;
            cluster k = pq.top();   pq.pop();
            for(auto x: k.c){
                grid[x.first][x.second] = -1;
            }
            ans += k.walls;
            while(!pq.empty()){
                cluster k1 = pq.top();  pq.pop();
                for(auto x: k1.uc){
                    grid[x.first][x.second] = 1;
                }   
            }
        } 
        return ans;
    }
};