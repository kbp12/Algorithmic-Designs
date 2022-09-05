class Solution {
public:
    int search(string s, int l){
        int n = s.size();
        set<string>sett;
        for(int i=0;i<=n-l;i++){
            if(sett.find(s.substr(i,l))!=sett.end()) return 1;
            else sett.insert(s.substr(i,l));
        }
        return -1;
    }
    
    int longestRepeatingSubstring(string s) {
        int r = s.size(), l = 1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(search(s,m)!=-1) l = m+1;
            else r = m-1;
        }
        return l-1;
    }
};