class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>>ans;
        for(auto path:paths){
            stringstream ss(path);
            string first,s;
            ss>>first;
            while(ss>>s){
                string temp = first + '/' + s.substr(0,s.find('('));
                string content = s.substr(s.find('(')+1, s.find(')')-s.find('(')-1);
                mpp[content].push_back(temp);
            }
        }
        for(auto m:mpp){
            if(m.second.size()>1){
                ans.push_back(m.second);
            }
        }
        return ans;
    }
};