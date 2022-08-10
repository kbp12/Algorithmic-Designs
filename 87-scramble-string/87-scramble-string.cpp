class Solution {
public:
    map<string,bool>mpp;
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n!=m) return false;
        if(s1==s2) return true;
        if(n==1) return false;
        string tmp = s1+"-"+s2;
        if(mpp.find(tmp)!=mpp.end()) return mpp[tmp];
        for(int i=1;i<n;i++){
            //dont change order
            bool noswap = isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i),s2.substr(i));
            if(noswap) return true;
            bool withswap = isScramble(s1.substr(0,i),s2.substr(n-i)) and isScramble(s1.substr(i),s2.substr(0,n-i));
            if(withswap) return true;
        }
        mpp[tmp] = false;
        return false;
    }
};