class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size();
        if(n==1) return 1;
        int ans = 2;
        for(int i=0;i<n;i++){
            int x = p[i][0], y = p[i][1];
            int same = 0;
            unordered_map<double,int>mpp;
            for(int j=0;j<n;j++){
                if(p[j][0]==x and p[j][1]==y){
                    same++;
                }else if(p[j][0] == x){
                    mpp[INT_MAX]++;
                }else{
                    double slope = (double)(p[j][1]-y)/(double)(p[j][0]-x);
                    mpp[slope]++;
                }
            }
            int curr = 0;
            for(auto it:mpp){
                curr = max(curr,it.second);
            }
            curr+=same;
            ans = max(ans,curr);
        }
        return ans;
    }
};