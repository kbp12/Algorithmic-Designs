class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<vector<int>>ans(n);
        ans[0].push_back(1);
        for(int i=1;i<n;i++){
            int siz = ans[i-1].size();
            ans[i].push_back(1);
            for(int j=1;j<siz;j++){
                ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans[i].push_back(1);
        }
        return ans[n-1];
    }
};