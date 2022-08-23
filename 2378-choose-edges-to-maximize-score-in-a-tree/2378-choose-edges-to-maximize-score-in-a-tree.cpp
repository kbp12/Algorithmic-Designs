class Solution {
public:
    pair<long long,long long> dfs(vector<pair<int,long long>>adj[], int i){
        long long best_i = 0, without_i = 0;
        for(auto [child,weight]:adj[i]){
            auto [with_child, without_child] = dfs(adj,child);
            best_i = max(best_i, max(weight,(long long)0) + without_child - with_child);
            without_i += max(with_child, without_child);
        }
        return {best_i+without_i, without_i};
    }
    
    long long maxScore(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<pair<int,long long>>adj[n];
        for(int i=1;i<n;i++){
            adj[edges[i][0]].push_back({i,edges[i][1]}); 
        }
        pair<long long,long long>ans = dfs(adj,0);
        return max(ans.first,ans.second);
    }
};