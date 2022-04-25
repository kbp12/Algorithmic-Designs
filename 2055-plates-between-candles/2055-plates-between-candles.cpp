class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n = s.length();
        vector<int>stars(n,0),lines(n,0);
        if(s[0]=='|'){lines[0] = 1;}
        else{ stars[0] = 1;}
        for(int i=1;i<n;i++){
            if(s[i] == '|'){
                lines[i] = lines[i-1]+1;
                stars[i] = stars[i-1];
            }else{
                stars[i] = stars[i-1]+1;
                lines[i] = lines[i-1];
            }
        }
        int m = q.size();
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            int a = q[i][0], b = q[i][1];
            int l = lines[a], r = lines[b];
            int lidx, ridx;
            if(s[a]=='|'){
                lidx = a;
            }else{
                int t = lines[a];
                int p = upper_bound(lines.begin(),lines.end(),t)-lines.begin();
                lidx = min(n-1,p);
            }
            if(s[b]=='|'){
                ridx = b;
            }else{
                int t = lines[b];
                //cout<<t<<endl;
                int p = lower_bound(lines.begin(),lines.end(),t)-lines.begin();
                ridx = max(0,p);
            }
            //cout<<lidx<<" "<<ridx<<endl;
            ans[i] = max(0,stars[ridx]-stars[lidx]);
        }
        return ans;
    }
};