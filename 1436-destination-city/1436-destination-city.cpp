class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>umap;
        set<string>s;
        for(auto path:paths){
            umap[path[0]] = path[1];
            s.insert(path[1]);
        }
        string start = "";
        for(auto it:umap){
            if(s.find(it.first)==s.end()){
                start = it.first;
                break;
            }
        }
        while(umap.find(start)!=umap.end()) start = umap[start];
        return start;
    }
};