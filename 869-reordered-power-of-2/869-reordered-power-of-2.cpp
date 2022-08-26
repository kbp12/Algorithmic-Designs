class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string>s;
        int j = 1;
        for(int i=0;i<30;i++){
            int k = j;
            string t = "";
            while(k){
                t.push_back('0'+k%10);
                k = k/10;
            }
            sort(t.begin(),t.end());
            s.insert(t);
            j*=2;
        }
        string t = "";
        while(n){
            t.push_back('0'+n%10);
            n = n/10;
        }
        sort(t.begin(),t.end());
        if(s.find(t)!=s.end()) return true;
        return false;
    }
    
};