class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        int ans = 0, n;
        string w = "";
        while(ss>>w){
            n = w.size();
            ans = n;
        }
        return ans;
    }
};