class Solution {
public:
    bool dfs(vector<int>adj[] , vector<int>& visit, vector<int>& color, int i, int c){
        visit[i] = true;
        color[i] = c;
        c = 1-c;
        for(auto next:adj[i]){
            if(visit[next]){
                if(color[next] != c) return false;
                continue;
            }
            dfs(adj,visit,color,next,c);
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(auto d:dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        vector<int>visit(n+1 , false);
        vector<int>color(n+1 , 0);
        for(int i=1;i<=n;i++){
            if(visit[i] == false){
                if(!dfs(adj, visit, color, i, 1)) return false;
            }
        }
        return true;
    }
};