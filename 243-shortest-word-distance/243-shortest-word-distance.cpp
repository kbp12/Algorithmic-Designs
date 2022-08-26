class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int j = -1, k = -1;
        int n = wordsDict.size();
        int ans = 1000000;
        for(int i=0;i<n;i++){
            if(wordsDict[i]==word1){
                if(k!=-1){
                    ans = min(ans,i-k);
                }
                j = i;
            }else if(wordsDict[i]==word2){
                if(j!=-1){
                    ans = min(ans,i-j);
                }
                k = i;
            }
        }
        return ans;
    }
};