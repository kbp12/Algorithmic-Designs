class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>>g(n);
        vector<int>indeg(n,0);
        for(auto edge:edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
            indeg[edge[1]]++;
        }
        queue<int>q;
        vector<int>ans;
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(indeg[i]==1){
                q.push(i);
                temp.push_back(i);
            }
        }
        ans = temp;
        while(!q.empty()){
            int siz = q.size();
            ans = temp;
            temp.clear();
            for(int i=0;i<siz;i++){
                int f = q.front(); q.pop();
                for(auto next:g[f]){
                    indeg[next]--;
                    if(indeg[next]==1){
                        temp.push_back(next);
                        q.push(next);
                    }
                }
            }
        }
        return ans;
    }
};