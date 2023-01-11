class Solution {
public:
    int dfs(int idx, vector<bool>& hasApple, vector<int>adj[],int parent){
        int sum = 0;
        for(int i=0;i<adj[idx].size();i++){
            if(adj[idx][i]!=parent){
                sum+=dfs(adj[idx][i],hasApple,adj,idx);
            }
        }
        if(sum){
            return sum+1;
        }
        if(hasApple[idx])
            return 1;
        return 0;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        int m = edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = dfs(0,hasApple,adj,-1);
        if(ans)
            ans = ans-1;
        return ans*2;
    }
};