class Solution {
public:
    vector<int> topStudents(vector<string>& pff, vector<string>& nff, vector<string>& rep, vector<int>& sid, int k) {
        unordered_set<string>pf,nf;
        for(auto p:pff){
            pf.insert(p);
        }
        for(auto n:nff){
            nf.insert(n);
        }
        unordered_map<int,int>umap;
        int sz = rep.size();
        for(int i=0;i<sz;i++){
            stringstream s(rep[i]);
            string temp;
            while(s >> temp){
                if(pf.find(temp) != pf.end()){
                    umap[sid[i]]+=3;
                }
                if(nf.find(temp) != nf.end()){
                    umap[sid[i]]-=1;
                }
            }
        }
        vector<pair<int,int>>v(sz);
        for(int i=0;i<sz;i++){
            if(umap[sid[i]]){
                v[i] = {umap[sid[i]] , sid[i]};
            }else{
                v[i] = {0 , sid[i]};
            }
        }
        sort(v.begin() , v.end(), [](pair<int,int>& p1 , pair<int,int>& p2){
            if(p1.first != p2.first) return p1.first>p2.first;
            return p1.second<p2.second;
        });
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            ans[i] = v[i].second;
        }
        return ans;
            
    }
};






