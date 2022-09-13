class Solution {
public:
    int ans = 0;
    pair<int,int> dfs(vector<int>adj[], int node,vector<int>& value){
        int nodes = 1, sum = value[node];
        for(auto next:adj[node]){
            pair<int,int>p = dfs(adj,next,value);
            sum+=p.second;
            nodes+=p.first;
        }
        if(sum==0){
            ans+=nodes;
            return {0,0};
        }
        return {nodes,sum};
    }
    
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<int>adj[nodes];
        for(int i=1;i<nodes;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(adj,0,value);
        return nodes-ans;
    }
};