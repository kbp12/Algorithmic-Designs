class Solution {
public:
    int strStr(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m==0) return 0;
        for(int i=0;i<n;i++){
            int j = 0;
            for(j=0;j<m and i+j<n;j++){
                if(s[i+j]!=t[j]){
                    break;
                }
            }
            if(j==m) return i;
        }
        return -1;
    }
};