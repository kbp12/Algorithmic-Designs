class DSU{
private:
    vector<int>parent;
    vector<int>rank;
public:
    DSU(int n){
        parent = vector<int>(n,-1);
        rank = vector<int>(n,1);
    }
    int find(int x){
        if(parent[x]<0) return x;
        return parent[x] = find(parent[x]);
    }
    bool merge(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb){
            return true;
        }
        if(rank[pa]>rank[pb]){
            parent[pb] = pa;
        }else if(rank[pa]<rank[pb]){
            parent[pa] = pb;
        }else{
            parent[pb] = pa;
            rank[pa]++;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int>parent(n,-1),ans1, ans2, ans3;
        bool mult = false, cycle = false;
        for(int i=0;i<n;i++){
            int a = edges[i][0], b = edges[i][1];
            if (parent[b-1]>0) {
                mult = true; 
                ans1 = {parent[b-1], b}; 
                ans2 = {a, b}; 
            }else{
                parent[b-1] = a; 
                if (dsu.merge(a-1,b-1)) {
                    cycle = true; 
                    ans3 = {a, b}; 
                }
            }
        }
        if(mult and cycle){
            return ans1;
        }
        if(mult){
            return ans2;
        }
        return ans3;
    }
};