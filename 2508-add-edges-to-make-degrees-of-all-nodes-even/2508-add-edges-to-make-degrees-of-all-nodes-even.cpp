class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        unordered_map<int ,set<int>>umap;
        vector<int>indeg(n+1,0) , v;
        for(auto e:edges){
            umap[e[0]].insert(e[1]);
            umap[e[1]].insert(e[0]);
            indeg[e[0]]++;
            indeg[e[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(indeg[i]%2){
                v.push_back(i);
                cnt++;
            }
        }
        int siz = v.size();
        if(cnt>4 or cnt==3 or cnt==1) return false;
        if(!siz) return true;
        if(siz == 2){
            int a = v[0] , b = v[1];
            for(int i=1;i<=n;i++){
                if(i==a or i==b) continue;
                if(umap[i].find(a) == umap[i].end() and umap[i].find(b) == umap[i].end()) return true;
            }
            if(umap[a].find(b) == umap[a].end()) return true;
            return false;
        }
        int a = v[0] , b = v[1] , c = v[2] , d = v[3];
        if(umap[a].find(b)==umap[a].end() and umap[c].find(d)==umap[c].end()) return true;
        if(umap[a].find(c)==umap[a].end() and umap[b].find(d)==umap[b].end()) return true;
        if(umap[a].find(d)==umap[a].end() and umap[c].find(b)==umap[c].end()) return true;
        return false;
    }
};