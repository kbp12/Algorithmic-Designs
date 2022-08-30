class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int>cnt(26,0);
        for(char ch:s){
            cnt[ch-'a']++;
        }
        int c = 0;
        for(int i = 0; i<26 ; i++){
            if(cnt[i]%2) c++;
        }
        return c<2;
    }
};