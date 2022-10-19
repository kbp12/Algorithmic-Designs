class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n+1];
        vector<int>ind(n+1,0);
        for(auto rel:relations){
            adj[rel[1]].push_back(rel[0]);
            ind[rel[0]]++;
        }
        vector<int>finish(n+1,0);
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(ind[i]==0){
                q.push(i);
                finish[i] = time[i-1];
            }
        }
        while(q.size()){
            int f = q.front(); q.pop();
            for(auto it:adj[f]){
                ind[it]--;
                finish[it] = max(finish[it] , finish[f]+time[it-1]);
                if(ind[it] == 0){
                    q.push(it);
                }
            }
        }
        return *max_element(finish.begin(),finish.end());
    }
};