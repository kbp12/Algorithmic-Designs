class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        int a[26] = {0};
        for(auto w:words2){
            int b[26] = {0};
            for(auto ch:w) b[ch-'a']++;
            for(int i=0;i<26;i++){
                a[i] = max(a[i],b[i]);
            }
        }
        for(auto w:words1){
            int b[26] = {0};
            for(auto ch:w) b[ch-'a']++;
            bool y = true;
            for(int i=0;i<26;i++){
                if(b[i]<a[i]){
                    y = false;
                    break;
                }
            }
            if(y){
                ans.push_back(w);
            }
        }
        return ans;
    }
};