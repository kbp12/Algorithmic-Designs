class Solution {
public:
    bool isItPossible(string w1, string w2) {
        vector<int>a(26,0),b(26,0);
        int p,q;
        for(auto ch:w1) a[ch-'a']++;
        for(auto ch:w2) b[ch-'a']++;
        int c1 = 0, c2 = 0;
        for(int i=0;i<26;i++){
            if(a[i]) c1++;
            if(b[i]) c2++;
        }
        
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                p = c1;
                q = c2;
                if(a[i]==0 or b[j]==0) continue;
                
                if(i == j and p==q){
                    return true;
                }
                else if(i==j) continue;
                
                if(b[i] == 0) q++;
                if(a[j] == 0) p++;
                if(a[i] == 1) p--;
                if(b[j] == 1) q--;
                
                if(p == q){
                    return true;
                }
            }
        }
        return false;
    }
};