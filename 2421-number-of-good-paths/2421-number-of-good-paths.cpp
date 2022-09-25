class DSU{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n, 0);
        rank.resize(n, -1);
        for (int i=0;i<n;i++){ parent[i] = i;}
    }
    int find(int x){
        if (parent[x]!=x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) 
            return;
        if(rank[px]>rank[py]) {
            parent[py] = px;
        }
        else if(rank[px]<rank[py]){
            parent[px] = py;
        }
        else{
            parent[py] = px;
            rank[px]++;
        }
        return;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        map<int, vector<int>> nodesat;
        for (int i = 0; i < n; i++) {
            nodesat[vals[i]].push_back(i);
        }
        vector<int>adj[n];
        for (auto& edge:edges) {
            int u = edge[0];
            int v = edge[1];
            if (vals[u] <= vals[v]) {
                adj[v].push_back(u);
            }
            if (vals[u] >= vals[v]) {
                adj[u].push_back(v);
            }
        }
        
        DSU *dsu = new DSU(n);
        int ans = 0;
        for (auto& value : nodesat) {
            int val = value.first;
            for (auto& node:value.second) {
                for (auto& next:adj[node]) {
                    dsu->merge(node,next);
                }
            }
            unordered_map<int, int> siz;
            for (auto& node : value.second) {
                siz[dsu->find(node)]++;
            }
            ans+= value.second.size();
            for (auto& [groupID, size] : siz) {
                if (size > 1) {
                    ans+= (size * (size - 1)) / 2;
                }
            }
        }
        return ans;
    }
};