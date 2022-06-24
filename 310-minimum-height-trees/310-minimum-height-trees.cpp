class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
        if(n==1) return {0};
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int siz = q.size();
            ans.clear();
            for(int i=0;i<siz;i++){
                int f = q.front(); q.pop();
                ans.push_back(f);
                for(auto it:adj[f]){
                    indegree[it]--;
                    if(indegree[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};