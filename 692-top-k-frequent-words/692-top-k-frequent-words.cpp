class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>cnt;
        for(auto &w:words){
            cnt[w]++;
        }
        vector<pair<int,set<string>>>v(501);
        for(auto c:cnt){
            v[c.second].second.insert(c.first);
        }
        vector<string>ans;
        int c = 0;
        for(int i=500;i>=0;i--){
            for(auto w:v[i].second){
                ans.push_back(w);
                c++;
                if(c==k) break;
            }
            if(c==k) break;
        }
        return ans;
    }
};