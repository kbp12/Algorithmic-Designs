class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int>f(26,0);
        for(int i=0;i<n;i++){
            f[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(f[i]){
                while(true){
                    bool yes = false;
                    for(int j=0;j<26;j++){
                        if(i!=j && f[j]==f[i] && f[i]){
                            yes = true;
                            break;
                        }
                    }
                    if(yes){
                        f[i]--;
                    }else{
                        break;
                    }
                }
            }
        }
        int c = 0;
        for(auto a:f) c+=a;
        return n-c;
    }
};