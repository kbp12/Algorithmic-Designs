class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> suffix(26);
        long long ans = 0;
        for (auto& idea:ideas) {
            suffix[idea[0]-'a'].insert(idea.substr(1));
        }
        
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                auto& set_a = suffix[i];
                auto& set_b = suffix[j];
                int common = 0;
                for (auto& item:set_a) {
                    common += set_b.count(item);
                }
                ans += 2*(set_a.size()-common)*(set_b.size()-common);
            }
        }
        return ans;
    }
};