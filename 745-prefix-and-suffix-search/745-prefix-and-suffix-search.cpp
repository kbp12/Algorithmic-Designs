class WordFilter {
public:
    unordered_map<string,int>umap;
    WordFilter(vector<string>& words) {
        int c = 1;
        for(string s:words){
            for(int j=1;j<=s.size();j++){
                string pre = s.substr(0,j);
                for(int k=0;k<=s.size();k++){
                    string suff = s.substr(k,s.size());
                    umap[pre+"|"+suff] = c;
                }
            }
            c++;
        }
    }
    
    int f(string prefix, string suffix) {
        prefix+="|"+suffix;
        return umap[prefix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */