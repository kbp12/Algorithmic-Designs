class Solution {
public:
    int dfs(int node, vector<int>&xor_subtree, int parent, vector<vector<int>>&adj, vector<int>&nums){
        int val=nums[node];
        for(auto &nbr:adj[node]){
            if(nbr!=parent){
                val^=dfs(nbr, xor_subtree, node, adj, nums);
            }
        }
        return xor_subtree[node]=val;
    }
    void dfs2(int node, vector<vector<int>>&children, int parent, vector<vector<int>>&adj){
        for(int &nbr:adj[node]){
            if(nbr!=parent){
                children[node][nbr]=true;
                dfs2(nbr, children, node, adj);
                for(int i=0;i<children[nbr].size();i++){
                    if(children[nbr][i]){
                        children[node][i]=true;
                    }
                }
            }
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>xor_subtree(n);
        dfs(0, xor_subtree, -1, adj, nums);
    
        
        vector<vector<int>>children(n, vector<int>(n));
        dfs2(0, children, -1, adj);
        
        int xa,xb,xc;
        int ans=1e9, xr=xor_subtree[0];
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
              
                int a=edges[i][0], b=edges[i][1], c=edges[j][0], d=edges[j][1];
                if(children[a][b])swap(a,b);
                if(children[c][d])swap(c,d);
                
                if(children[a][c]){
                    xc=xor_subtree[c];
                    xa=(xor_subtree[a]^xc);
                    xb=(xr^xor_subtree[a]);
                }else if(children[c][a]){
                    xa=xor_subtree[a];
                    xc=(xor_subtree[c]^xor_subtree[a]);
                    xb=(xr^xor_subtree[c]);
                }
                else{
                    xa=xor_subtree[a];
                    xc=xor_subtree[c];
                    xb=(xr^xa^xc);
                }
                int curr=max(xa, max(xb,xc))-min(xa, min(xb,xc));
                ans=min(ans, curr);
            }
        }
        return ans;
    }
};