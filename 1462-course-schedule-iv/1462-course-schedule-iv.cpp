class Solution {
public:
    bool dfs(vector<int>adj[], vector<bool>& visit, int u, int v){
        if(visit[u]) return false;
        visit[u] = true;
        if(u==v) return true;
        bool yes = false;
        for(auto next:adj[u]){
            yes|=dfs(adj,visit,next,v);
        }
        return yes;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>adj[n];
        for(auto pre:prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        int q = queries.size();
        vector<bool>ans(q);
        for(int i=0;i<q;i++){
            vector<bool>visit(n,false);
            if(dfs(adj,visit,queries[i][0],queries[i][1])){
                ans[i] = true;
            }else{
                ans[i] = false;
            }
        }
        return ans;
    }
};