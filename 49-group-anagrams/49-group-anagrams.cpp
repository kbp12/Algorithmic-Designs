class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<vector<int>,vector<string>>m;
        for(int i=0;i<n;i++){
            vector<int>temp(26,0);
            int k = strs[i].length();
            for(int j=0;j<k;j++) temp[strs[i][j]-'a']++;
            m[temp].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:m){ ans.push_back(it.second);}
        return ans;
    }
};