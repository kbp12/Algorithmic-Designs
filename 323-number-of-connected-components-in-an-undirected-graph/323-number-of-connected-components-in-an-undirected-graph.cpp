class Solution {
public:
    void dfs(vector<int>adj[], int i,vector<int>& visit){
        visit[i] = 1;
        for(auto next:adj[i]){
            if(visit[next]==false){
                dfs(adj,next,visit);
            }
        }
        return;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>visit(n,false);
        int components = 0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(adj,i,visit);
                components++;
            }
        }
        return components;
    }
};