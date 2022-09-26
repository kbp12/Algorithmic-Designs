class DSU{
private:
    vector<int>parent;
    vector<int>rank;
public:
    DSU(){
        parent.resize(26);
        rank.resize(26,1);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(parent[x]!=x) return find(parent[x]);
        return x;
    }
    
    void merge(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return;
        if(rank[pa]>rank[pb]){
            parent[pb] = pa;
        }else if(rank[pb]>rank[pa]){
            parent[pa] = pb;
        }else{
            parent[pb] = pa;
            rank[pa]++;
        }
        return;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu;
        for(auto eq:equations){
            if(eq[1]=='='){
                dsu.merge(eq[0]-'a',eq[3]-'a');
            }
        }
        for(auto eq:equations){
            if(eq[1]=='!'){
                if(dsu.find(eq[0]-'a') == dsu.find(eq[3]-'a')) return false;
            }
        }
        return true;
    }
};