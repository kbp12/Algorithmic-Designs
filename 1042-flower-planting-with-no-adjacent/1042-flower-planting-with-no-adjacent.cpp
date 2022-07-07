class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>ans(n,0);
        vector<int>adj[n];
        for(int i=0;i<paths.size();i++){
            int u = paths[i][0], v = paths[i][1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        for(int i=0;i<n;i++){
            vector<bool>used(5,false);
            for(int it:adj[i]){
                used[ans[it]] = true;
            }
            for(int c=1;c<5;c++){
                if(used[c]==false){
                    ans[i] = c;
                    break;
                }
            }
        }
        return ans;
    }
};