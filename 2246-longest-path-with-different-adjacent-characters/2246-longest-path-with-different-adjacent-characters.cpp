class Solution {
public:
    int ans = 0;
    int dfs(vector<int>adj[] , int node, string &s){
        int max1 = 0, max2 = 0,temp;
        for(auto child:adj[node]){
            temp = dfs(adj,child,s);
            if(s[node] != s[child]){
                if(temp>max1){max2 = max1, max1 = temp;}
                else max2 = max(max2 , temp);
            }
        }
        ans = max(ans , max1 + max2 + 1);
        return max1 + 1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> adj[n];
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(adj,0,s);
        return ans;
    }
};