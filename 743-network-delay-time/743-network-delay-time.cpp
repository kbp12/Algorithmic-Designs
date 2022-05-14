class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        vector<bool>visit(n,false);
        vector<int>dist(n,1e9);
        dist[k-1] = 0;
        for(int x=0;x<n;x++){
            int idx = -1, val = 1e9;
            for(int i=0;i<n;i++){
                if(visit[i]==false && (idx==-1 || dist[i]<val)){
                    idx = i;
                    val = dist[idx];
                }
            }
            if(idx==-1 || val==1e9) return -1;
            visit[idx] = true;
            for(int i=0;i<adj[idx].size();i++){
                int a = adj[idx][i].first;
                int b = adj[idx][i].second;
                dist[a] = min(dist[a], dist[idx]+b);
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            if(visit[i]==false) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};