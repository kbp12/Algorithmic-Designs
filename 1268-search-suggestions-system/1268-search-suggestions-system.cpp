class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        unordered_map<string,set<string>>umap;
        for(int i=0;i<p.size();i++){
            int m = p[i].length();
            string temp = "";
            for(int j=0;j<m;j++){
                temp+=p[i][j];
                umap[temp].insert(p[i]);
            }
        }
        int n = s.length();
        vector<vector<string>>ans(n);
        string temp = "";
        for(int i=0;i<n;i++){
            temp+=s[i];
            int c = 0;
            for(auto str:umap[temp]){
                ans[i].push_back(str);
                c++;
                if(c==3) break;
            }
        }
        return ans;
    }
};