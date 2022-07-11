class Solution {
public:
    vector<int>low;
    vector<int>tin;
    vector<bool>visited;
    vector<vector<int>>ans;
    int timer;
    
    void dfs(vector<int>adj[], int node, int par){
        visited[node] = true;
        low[node] = timer;
        tin[node] = timer;
        timer++;
        for(auto next:adj[node]){
            if(next == par){
                continue;
            }else if(!visited[next]){
                dfs(adj,next,node);
                low[node] = min(low[node],low[next]);
                if(low[next]>tin[node]){
                    ans.push_back({node,next});
                }
            }else{
                low[node] = min(low[node],low[next]);
            }
        }
        return;
    }
    
    void dfs_loop(vector<int>adj[], int n){
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,-1);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        ans.clear();
        timer = 0;
        low.assign(n,-1);
        tin.assign(n,-1);
        visited.assign(n,false);
        dfs_loop(adj,n);
        return ans;
    }
};