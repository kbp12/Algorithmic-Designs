class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        int m = prereq.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<m;i++){
            adj[prereq[i][1]].push_back(prereq[i][0]);
            indegree[prereq[i][0]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            int f = q.front(); q.pop();
            for(auto next:adj[f]){
                indegree[next]--;
                if(indegree[next]==0){
                    ans.push_back(next);
                    q.push(next);
                }
            }
        }
        if(ans.size()==n) return ans;
        return {};
    }
};