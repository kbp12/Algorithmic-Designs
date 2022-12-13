class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool>mark(26 , false);
        for(auto ch:allowed) mark[ch-'a'] = true;
        int count = 0;
        for(auto word : words){
            bool yes = true;
            for(auto ch : word){
                if(mark[ch-'a'] == false){
                    yes = false;
                    break;
                }
            }
            if(yes) count++;
        }
        return count;
    }
};