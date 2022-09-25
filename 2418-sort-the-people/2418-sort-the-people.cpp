class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) {
        unordered_map<int,string>u;
        for(int i=0;i<h.size();i++){
            u[h[i]] = n[i];
        }
        sort(h.begin(),h.end(),greater<int>());
        vector<string>ans;
        for(int i=0;i<h.size();i++){
            ans.push_back(u[h[i]]);
        }
        return ans;
    }
};