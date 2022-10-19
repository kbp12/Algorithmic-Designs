class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        for(auto w:words) m[w]++;
        vector<set<string>>v(501);
        for(auto it:m){
            v[it.second].insert(it.first);
        }
        vector<string>ans;
        for(int i=500;i>=0;i--){
            for(auto element:v[i]){
                ans.push_back(element); k--;
                if(k==0) return ans;
            }
        }
        return ans;
    }
};