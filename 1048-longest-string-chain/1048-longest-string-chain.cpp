class Solution {
public:
    bool check(string s1,string s2){
        int n = s2.length();
        bool done = false;
        for(int i=0,j=0;i<n;i++){
            if(s2[i]==s1[j]){
                j++;
            }else{
                if(done) return false;
                done = true;
                j++;
                i--;
            }
        }
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string s1, string s2){
            return s1.length()<s2.length();
        });
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j=i-1;j>=0;j--){
                if(words[j].length()==words[i].length()-1){
                    if(check(words[i],words[j])){
                        dp[i] = max(dp[i],1+dp[j]);
                    }
                }
            }
        }
        int ans = 1;
        for(int i=0;i<n;i++) ans = max(ans,dp[i]);
        return ans;
    }
};