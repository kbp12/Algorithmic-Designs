class Solution {
public:
    int ans = 0;
    
    void recur(vector<int>&c){
        for(int i=0;i<26;i++){
            if(c[i]){
                c[i]--;
                ans++;
                recur(c);
                c[i]++;
            }
        }
        return;
    }
    
    int numTilePossibilities(string tiles) {
        vector<int>c(26,0);
        for(auto t:tiles){
            c[t-'A']++;
        }
        recur(c);
        return ans;
    }
};