class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n = paint.size();
        vector<int>ans(n);
        vector<int>dp(50005,0);
        for(int i=0;i<n;i++){
            int a = paint[i][0];
            int l = paint[i][1]-paint[i][0];
            int c = 0;
            for(int j=a;j<a+l;){
                if(dp[j]==0){
                    c++;
                    dp[j] = a+l-j;
                    j++;
                }else{
                    j+=dp[j];
                }
            }
            ans[i] = c;
        }
        return ans;
    }
};