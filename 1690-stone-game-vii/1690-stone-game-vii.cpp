class Solution {
public:
    int dp[1002][1002];
	int getMaxDiff(vector<int> &v,int i,int j,int sum)
    {
        if(i>=j)
            return 0;
        if(sum<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=max(sum-v[i]-getMaxDiff(v,i+1,j,sum-v[i]),sum-v[j]-getMaxDiff(v,i,j-1,sum-v[j]));
        
    }
    int stoneGameVII(vector<int>& stones) 
    {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto i:stones)
            sum+=i;
        return getMaxDiff(stones,0,stones.size()-1,sum); 
        
    }
};