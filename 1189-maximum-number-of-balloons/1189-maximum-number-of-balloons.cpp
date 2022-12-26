class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>v(26,0);
        for(auto ch:text){
            v[ch-'a']++;
        }
        return min({v[0] , v[1] , v[11]/2 , v[13] , v[14]/2});
    }
};