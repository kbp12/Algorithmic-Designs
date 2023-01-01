class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[1001][1001];
    bool is_prime(char c){
        return c == '2' or c == '3' or c == '5' or c == '7';
    }
    int recur(int i , string &s , int k , int mini){
        if(i == s.size()){
            return k == 0;
        }
        if(k == 0 or s.size() - i < mini){
            return 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        
        int ans = 0;
        if(is_prime(s[i])){
            
            for(int j = i + 1; j < s.size() ;j++){
                if(is_prime(s[j]) == false and j - i + 1 >= mini){
                    ans = (ans + recur(j + 1 , s, k - 1, mini )) % mod;
                }
            }
        }
        return dp[i][k] = ans;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        
        memset(dp , -1 ,sizeof(dp));
        
        return recur(0 , s , k , minLength);
    }
};