class Solution {
public:
    set<pair<int,int>>s;
    int dfs(vector<vector<pair<int,int>>>& adj, int node){
        int dist = INT_MAX;
        for(auto next:adj[node]){
            if(s.find({node , next.first}) == s.end() and s.find({next.first , node}) == s.end()){
                int val = next.second;
                s.insert({node , next.first});
                int d = dfs(adj,next.first);
                dist = min({dist , d , val});
            }
        }
        return dist;
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto road:roads){
            adj[road[0]].push_back({road[1] , road[2]});
            adj[road[1]].push_back({road[0] , road[2]});
        }
        
        return dfs(adj,1);
    }
};