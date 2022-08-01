class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>g[n];
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                g[j].push_back(i);
                indeg[i]++;
            }
        }
        set<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                ans.insert(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                int f = q.front(); q.pop();
                for(auto next:g[f]){
                    indeg[next]--;
                    if(indeg[next]==0){
                        q.push(next);
                        ans.insert(next);
                    }
                }
            }
        }
        return vector<int>(ans.begin(),ans.end());
    }
};