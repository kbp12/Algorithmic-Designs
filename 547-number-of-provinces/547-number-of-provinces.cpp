class Solution {
public:
    void bfs(int i, vector<vector<int>>&adj){
        if(adj[i][i]==0) return;
        adj[i][i] = 0;
        for(int j=0;j<adj.size();j++){
            if(adj[i][j]){
                bfs(j,adj);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size(),count = 0;
        for(int i=0;i<n;i++){
            if(adj[i][i]){
                count++;
                bfs(i,adj);
            }
        }
        return count;
    }
};