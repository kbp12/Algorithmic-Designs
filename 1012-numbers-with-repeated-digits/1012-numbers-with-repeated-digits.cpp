class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        int m = n;
        string s = "";
        while(n>0){
            int d = n%10;
            s.push_back('0'+d);
            n = n/10;
        }
        reverse(s.begin(),s.end());
        int l = s.size();
        int ans = 0;
        for(int i=1;i<l;i++){
            int temp = 9;
            int k = 9;
            for(int j=1;j<i;j++){
                temp = temp*k; k--;
            }
            ans+=temp;
        }
        
        set<int>g;
        for(int i=0;i<l;i++){
            int it = s[i]-'0';
            int j = 0;
            if(i==0) j=1;
            for(; j<it;j++){
                if(g.find(j)==g.end()){
                    int rem = 10-(i+1);
                    int lrem = l-(i);
                    int temp = 1;
                    for(int k=1;k<lrem;k++){
                        
                        temp = temp*rem;
                        rem--;
                    }
                    ans+=temp;
                }
            }
            if(g.find(it)!=g.end()) break;
            g.insert(it);
        }
        if(g.size()==l) ans++;
        return m-ans;
    }
};