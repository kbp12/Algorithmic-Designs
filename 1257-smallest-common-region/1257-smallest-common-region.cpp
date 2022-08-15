class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        int n = regions.size();
        unordered_map<string,string>parent;
        for(int i=0;i<n;i++){
            int m = regions[i].size();
            for(int j=1;j<m;j++){
                parent[regions[i][j]] = regions[i][0];
            }
        }
        unordered_set<string>s;
        s.insert(region1);
        while(parent.find(region1)!=parent.end()){
            s.insert(parent[region1]);
            region1 = parent[region1];
        }
        while(s.find(region2)==s.end()){
            region2 = parent[region2];
        }
        return region2;
    }
};