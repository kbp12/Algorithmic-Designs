class Solution {
public:
    vector<int>dist;
    int ans;
    vector<bool>visit;
    void dfs(int i,vector<int>& edges, int d){
        if(visit[i]) return;
        if(edges[i]==-1){
            visit[i] = true;
            return;
        }
        if(dist[i]!=-1){
            ans = max(ans,d-dist[i]);
            visit[i] = true;
            return;
        }
        dist[i] = d;
        dfs(edges[i],edges,d+1);
        visit[i] = true;
        dist[i] = -1;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        dist = vector<int>(n,-1);
        visit = vector<bool>(n,false);
        ans = -1;
        for(int i=0;i<n;i++){
            if(visit[i]==false){
                dfs(i,edges,0);
            }
        }
        return ans;
    }
};