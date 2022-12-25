class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        int n = s.size();
        int c111 = 0, c222 = 0, c333 = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='a') c111++;
            else if(s[i]=='b') c222++;
            else c333++;
        }
        int l=1,r=n,m;
        int ans = n;
        if(c111<k or c222<k or c333<k) return -1;
        while(l<=r){
            unordered_map<int,int>u1;
            bool  ok = false;
            m = l+(r-l)/2;
            for(int i=0;i<m;i++){
                if(s[i]=='a') u1[1]++;
                else if(s[i]=='b') u1[2]++;
                else u1[3]++;
            }
            if(u1[1]>=k and u1[2]>=k and u1[3]>=k){
                ok = true;
            }
                int j=m-1;
                for(int i=n-1; i>=0 and j>=0;i--){
                    if(s[j]=='a') u1[1]--;
                    else if(s[j]=='b') u1[2]--;
                    else u1[3]--;
                    
                    if(s[i]=='a') u1[1]++;
                    else if(s[i]=='b') u1[2]++;
                    else u1[3]++;
                    
                    if(u1[1]>=k and u1[2]>=k and u1[3]>=k){
                        ok = true;
                    }
                    j--;
                }
            if(ok){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};