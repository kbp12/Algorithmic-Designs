class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size(), ans = 0;
        for(int i=0;i<n;i++){
            if(word.find(patterns[i])!=string::npos) ans++;
        }
        return ans;
    }
};