class MagicDictionary {
public:
    MagicDictionary() {
        
    }
    unordered_set<string>u,u1;
    void buildDict(vector<string> d) {
        for(auto it:d){
            u1.insert(it);
            int n = it.size();
            for(int i=0;i<n;i++){
                string s = it;
                s[i] = '#';
                if(u.find(s)!=u.end()){
                    s[i] = '%';
                    u.insert(s);
                }
                u.insert(s);
            }
        }
    }
    
    bool search(string s) {
        int n = s.length();
        for(int i=0;i<n;i++){
            string a = s;
            a[i] = '%';
            if(u.find(a)!=u.end()) return true;
        }
        if(u1.find(s)!=u1.end()) return false;
        for(int i=0;i<n;i++){
            string a = s;
            a[i] = '#';
            if(u.find(a)!=u.end()) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */