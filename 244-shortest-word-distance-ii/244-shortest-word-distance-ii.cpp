class WordDistance {
public:
    unordered_map<string,vector<int>>mpp;
    WordDistance(vector<string>& wordsDict) {
        int i = 0;
        for(auto word:wordsDict){
            mpp[word].push_back(i); i++;
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& v1 = mpp[word1];
        vector<int>& v2 = mpp[word2];
        int ans = 1e6;
        int i = 0, j = 0;
        while(i<v1.size() and j<v2.size()){
            if(v1[i]<v2[j]){
                ans = min(ans,v2[j]-v1[i]);
                i++;
            }else{
                ans = min(ans,v1[i]-v2[j]);
                j++;
            }
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */