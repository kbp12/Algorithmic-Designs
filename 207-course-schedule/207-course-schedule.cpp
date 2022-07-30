class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>indeg(n,0);
        vector<int>adj[n];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        vector<bool>taken(n,false);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                taken[i] = true;
                q.push(i);
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int f = q.front(); q.pop();
                for(auto ad:adj[f]){
                    indeg[ad]--;
                    if(indeg[ad]==0){
                        taken[ad] = true;
                        q.push(ad);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!taken[i]) return false;
        }
        return true;
    }
};