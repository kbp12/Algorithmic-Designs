class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string>u;
        int m = pow(2,k);
        for(int i=0;i<=n-k;i++){
            string s2 = s.substr(i,k);
            if(u.find(s2)==u.end()){
                u.insert(s2);
            }
            if(u.size()==m) return true;
        }
        return false;
    }
};