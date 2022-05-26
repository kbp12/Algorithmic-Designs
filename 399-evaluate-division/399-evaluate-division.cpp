class Solution {
public:
        double search(string s,string e,unordered_set<string>& visited,unordered_map<string,unordered_map<string,double>>& mpp){
        if(mpp.find(s)==mpp.end())
            return -1.0;
            
        if(mpp[s].find(e)!=mpp[s].end())
            return mpp[s][e];
        visited.insert(s);
            
        for(auto it:mpp[s])
        {
            if(visited.find(it.first)==visited.end())
            {
                double res = search(it.first,e,visited,mpp);
                if(res != -1.0){
                    res = res*it.second;
                    return res;
                }
            }       
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& vals, vector<vector<string>>& q) {
        unordered_map<string,unordered_map<string,double>> mpp;
        
        for(int i=0;i<eq.size();i++){
            string f = eq[i][0];
            string t = eq[i][1];
            mpp[f].insert({t,vals[i]});
            double temp = 1/vals[i];
            mpp[t].insert({f,temp});
        }
        
        vector<double> ans(q.size());
        for(int i=0;i<q.size();i++)
        {
            unordered_set<string> visited;
            ans[i] = search(q[i][0],q[i][1],visited,mpp);
        }
        return ans;   
    }    
};