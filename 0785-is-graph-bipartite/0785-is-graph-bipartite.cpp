class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int c){
        color[node] = c;
        int nc = 0;
        if(c == 1) nc = 2;
        else nc = 1;
        for(auto next:graph[node]){
            if(color[next] == c) return false;
            if(color[next] == nc) continue;
            if(!dfs(next,graph,color,nc)) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++){
            if(color[i] == 0){
                if(!dfs(i,graph,color,1)){
                    return false;
                }
            }
        }
        return true;
    }
};