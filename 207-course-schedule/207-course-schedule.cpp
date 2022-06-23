class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        int m = prereq.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<m;i++){
            adj[prereq[i][1]].push_back(prereq[i][0]);
            indegree[prereq[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int f = q.front(); q.pop();
            for(auto it:adj[f]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]) return false;
        }
        return true;
    }
};