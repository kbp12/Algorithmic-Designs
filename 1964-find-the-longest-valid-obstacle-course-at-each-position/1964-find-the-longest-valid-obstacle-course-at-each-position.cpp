class Solution {
public:
    int bs(vector<int>& dp, int t){
        int i = 0, j = dp.size()-1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(dp[m]<=t){
                i = m+1;
            }else{
                j = m-1;
            }
        }
        if(dp[i]<=t) return i+1;
        return i;
    }
    
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        int n = ob.size();
        vector<int>dp;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(dp.size()==0 or dp[dp.size()-1]<=ob[i]){
                dp.push_back(ob[i]);
                ans[i] = dp.size();
            }else{
                int pos = bs(dp,ob[i]);
                ans[i] = pos+1;
                dp[pos] = ob[i];
            }
        }
        return ans;
    }
};