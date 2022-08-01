class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>g[n];
        vector<int>indeg(n,0);
        for(auto rich:richer){
            g[rich[0]].push_back(rich[1]);
            indeg[rich[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = i;
        }
        while(!q.empty()){
            int f = q.front(); q.pop();
            for(auto next:g[f]){
                if(quiet[ans[next]]>quiet[ans[f]]){
                    ans[next] = ans[f];
                }
                indeg[next]--;
                if(indeg[next]==0){
                    q.push(next);
                }
            }
        }
        return ans;
    }
};