class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>graph[n];
        int m = edges.size();
        vector<int>indegree(n,0);
        for(int i=0;i<m;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<vector<int>>ans(n);
        while(!q.empty()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                int f = q.front(); q.pop();
                int k = graph[f].size();
                for(int j=0;j<k;j++){
                    
                    ans[graph[f][j]].push_back(f);
                    int l = ans[f].size();
                    for(int it=0;it<l;it++){
                        if(find(ans[graph[f][j]].begin(),ans[graph[f][j]].end(),ans[f][it])==ans[graph[f][j]].end()){
                            ans[graph[f][j]].push_back(ans[f][it]);
                        }
                    }
                    
                    indegree[graph[f][j]]--;
                    if(indegree[graph[f][j]]==0){
                        q.push(graph[f][j]);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};