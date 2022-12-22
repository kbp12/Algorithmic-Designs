class Solution {
public:
    void dfs1(int node, int par, vector<int>adj[] , vector<int>& dp, vector<int>& size){
        size[node] = 1;
        for(auto next:adj[node]){
            if(next == par) continue;
            dfs1(next,node,adj,dp,size);
            size[node]+=size[next];
            dp[node]+=dp[next]+size[next];
        }
        return;
    }
    
    void reroot(int from , int to, vector<int>& dp, vector<int>& size){
        dp[from]-=(size[to] + dp[to]);
        size[from]-= size[to];
        
        size[to]+=size[from];
        dp[to]+=(dp[from] + size[from]);
        return;
    }
    
    void dfs2(int node, int par, vector<int>adj[], vector<int>& dp, vector<int>& size, vector<int>& ans){
        ans[node] = dp[node];
        for(auto next: adj[node]){
            if(next == par) continue;
            reroot(node, next, dp, size);
            dfs2(next, node, adj, dp, size, ans);
            reroot(next, node, dp, size);
        }
        return;
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>dp(n,0) , size(n,0) , ans(n,0);
        dfs1(0, -1, adj, dp, size);
        dfs2(0, -1, adj, dp, size, ans);
        return ans;
    }
};