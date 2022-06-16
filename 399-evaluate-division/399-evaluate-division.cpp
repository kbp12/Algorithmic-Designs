class Solution {
public:
    double bfs(string s, string e, unordered_set<string>&visit, unordered_map<string,unordered_map<string,double>>&mp){
        if(mp[s].size()==0) return -1.0;
        if(mp[s].find(e)!=mp[s].end()){
            return mp[s][e];
        }
        visit.insert(s);
        for(auto it:mp[s]){
            if(visit.find(it.first)==visit.end()){
                double res = bfs(it.first,e,visit,mp);
                if(res!=-1){
                    res *= it.second;
                    return res;
                }
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>>mp;
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]].insert({equations[i][1],values[i]});
            double d = (double)1/values[i];
            mp[equations[i][1]].insert({equations[i][0],d});
        }
        vector<double>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            unordered_set<string>visit;
            ans[i] = bfs(queries[i][0],queries[i][1],visit,mp);
        }
        return ans;
    }
};