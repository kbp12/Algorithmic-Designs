class Solution {
public:
    int d;
    bool dfs(vector<int>adj[] , int node, vector<bool>& visited){
        if(visited[node]) return false;
        visited[node] = true;
        if(node == d) return true;
        for(auto next:adj[node]){
            if(dfs(adj,next,visited)) return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        d = destination;
        vector<int>adj[n];
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);
        return dfs(adj,source,visited);
    }
};