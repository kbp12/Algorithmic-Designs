class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n];
        vector<int>t(n,INT_MAX);
        t[k-1] = 0;
        for(auto time:times){
            adj[time[0]-1].push_back({time[1]-1,time[2]});
        }
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++){
            int idx = -1;
            int val = INT_MAX;
            for(int j=0;j<n;j++){
                if(visit[j]==false and t[j]<val){
                    idx = j;
                    val = t[j];
                }
            }
            if(idx==-1) return -1;
            visit[idx] = true;
            for(auto c:adj[idx]){
                if(visit[c.first]==false and t[idx]+c.second<t[c.first]){
                   t[c.first] = t[idx]+c.second;
                }
            }
        }
        int min_time = INT_MIN;
        for(int i=0;i<n;i++){
            min_time = max(min_time,t[i]);
        }
        return min_time;
    }
};