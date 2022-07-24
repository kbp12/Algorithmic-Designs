class Solution {
public:
    string bestHand(vector<int>& r, vector<char>& s) {
        if(s[0]==s[1] && s[1]==s[2] && s[2]==s[3] && s[3]==s[4]){
            return "Flush";
        }
        map<int,int>m;
        m[r[0]]++;
        m[r[1]]++;
        m[r[2]]++;
        m[r[3]]++;
        m[r[4]]++;
        int maxc = 0;
        for(auto it:m){
            maxc = max(maxc,it.second);
        }
        if(maxc>=3){
            return  "Three of a Kind";
        }
        if(maxc==2){
            return  "Pair";
        }
        return "High Card";
    }
};