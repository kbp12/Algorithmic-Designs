class Solution {
public:
    vector<int>depths;
    vector<int>temp;
    
    int dfs(int node, vector<int>adj[]){
        if(depths[node]!=-1) return depths[node];
        int ans = 0;
        for(auto next:adj[node]){
            ans = max(ans,dfs(next,adj));
        }
        depths[node] = 1+ans;
        return 1+ans;
    }
    
    vector<int> dfs2(vector<int>adj[], int node){
        if(depths[node]!=-1)
            return {node, depths[node], 0};
        depths[node] = 0;
        vector<int>t = dfs2(adj,temp[node]);
        if(t[2]){
            return {t[0],t[1],1};
        }
        depths[node] = 1+t[1];
        if(node == t[0])
            return {t[0],depths[node],1};
        return {t[0],depths[node],0};
    }
    
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        temp = fav;
        depths.assign(n,-1);
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            adj[fav[i]].push_back(i);
        }
        
        //case 1 where 2 nodes are interdependent 
        int ans1 = 0;
        for(int i=0;i<n;i++){
            if(depths[i]!=-1){
                continue;
            }
            if(fav[fav[i]] == i){
                depths[i] = 0;
                depths[fav[i]] = 0;
                int a = 0, b = 0;
                for(auto next:adj[i]){
                    if(next == fav[i]){
                        continue;
                    }
                    int t = dfs(next,adj);
                    a = max(a,t);
                }
                for(auto next:adj[fav[i]]){
                    if(next == i){
                        continue;
                    }
                    int t = dfs(next,adj);
                    b = max(b,t);
                }
                ans1+= a+b+2;
            }
        }
        
        //case where we are getting a cycle in between traversal
        int ans2 = 0;
        for(int i=0;i<n;i++){
            if(depths[i]!=-1){
                continue;
            }
            vector<int>t = dfs2(adj,i);
            if(t[2]){
                ans2 = max(ans2,t[1]);
            }
        }
        return max(ans1,ans2);
    }
};