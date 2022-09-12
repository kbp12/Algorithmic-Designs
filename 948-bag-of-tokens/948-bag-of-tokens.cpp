class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int ans = 0, i=0, j = n-1, score = 0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++; i++; 
            }else{
                if(score==0) break;
                else{
                    power+=tokens[j];
                    score--; j--;
                }
            }
            ans = max(ans,score);
        }
        return ans;
    }
};