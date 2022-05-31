class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        vector<bool>visited(n,false);
        vector<int>time(n,1e9);
        time[k-1] = 0;
        for(int i=0;i<n;i++){
            int idx = -1;
            for(int j=0;j<n;j++){
                if(visited[j]==false && (idx==-1 || time[j]<time[idx])){
                    idx = j;
                }
            }
            if(idx==-1 || time[idx]==1e9) return -1;
            visited[idx] = true;
            for(int p=0;p<adj[idx].size();p++){
                int a = adj[idx][p].first;
                int b = adj[idx][p].second;
                time[a] = min(time[a],time[idx]+b);
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            if(visited[i]==false) return -1;
            ans = max(ans,time[i]);
        }
        return ans;
    }
};