class Solution {
public:
    int shortestWay(string s, string t) {
        int n = s.size(), m = t.size();
        int j = 0, ans = 1;
        for(int i=0;i<m;i++){
            bool y = false;
            while(j<n){
                if(s[j]==t[i]){
                    y = true;
                    break;
                }
                j++;
            }
            if(y){
                if(j==n-1 and i!=m-1) ans++;
                j = (j+1)%n;
                continue;
            }
            ans++;
            j = 0;
            while(j<n){
                if(s[j]==t[i]){
                    y = true;
                    break;
                }
                j++;
            }
            if(y){
                if(j==n-1 and i!=m-1) ans++;
                j = (j+1)%n;
                continue;
            }
            return -1;
        }
        return ans;
    }
};