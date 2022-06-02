class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        int m = r.size();
        int ans = 0;
        int prev = 0;
        sort(r.begin(),r.end());
        int c = 0;
        for(int i=0;i<m;i++){
            if(prev==r[i][0]){
                if(r[i-1][1]==1 && r[i][1]==10) ans+=2;
                else if(r[i-1][1]<=3 && r[i][1]>=8) ans++;
                else if(r[i-1][1]==1 && r[i][1]>=6) ans++;
                else if(r[i][1]==10 && r[i-1][1]<=5) ans++;
            }else{
                c++;
                if(prev){
                    if(r[i-1][1]==1) {ans+=2;}
                    else if(r[i-1][1]<=5) {ans++;}
                }
                if(r[i][1]==10)
                    ans+=2;
                else if(r[i][1]>=6)
                    ans++;
                prev = r[i][0];
            }
        }
        if(r[m-1][1]==1) ans+=2;
        else if(r[m-1][1]<=5) ans++;
        c = n-c;
        ans+= 2*c;
        return ans;
    }
};