class Solution {
public:
    bool wordPattern(string p, string s) {
        stringstream ss(s);
        vector<string>v;
        string w;
        while(ss>>w){
            v.push_back(w);
        }
        int n = p.length();
        if(n!=v.size()) return false;
        map<char,string>mp;
        map<string,char>sch;
        for(int i=0;i<n;i++){
            if(mp.find(p[i])==mp.end()){
                if(sch.find(v[i])==sch.end()){
                    mp[p[i]] = v[i];
                    sch[v[i]] = p[i];
                }else{
                    return false;
                }
            }else{
                if(v[i] == mp[p[i]]){
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};