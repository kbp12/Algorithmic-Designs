class Solution {
public:

   int dp[501][51][51];
	int util(int t,int m,int c,vector<vector<int>>&graph,int n){
    if(t==5*n) dp[t][m][c]=0;
    if(m==0) return dp[t][m][c]=1;
    if(m==c) return dp[t][m][c]=2;
    if(dp[t][m][c]!=-1)
        return dp[t][m][c];
    int turn=t%2;
    if(turn==0){
        bool flag=true;
        for(int i=0;i<graph[m].size();i++){
            int winner=util(t+1,graph[m][i],c,graph,n);
            if(winner==1)
                return dp[t][m][c]=1;
            else if(winner!=2)
                flag=false;
        }
        if(!flag)
           return dp[t][m][c]=0;
        else 
             return dp[t][m][c]=2;      
    }
    else{
        bool flag=true;
        for(int i=0;i<graph[c].size();i++){
            if(graph[c][i]!=0){
            int winner=util(t+1,m,graph[c][i],graph,n);
            if(winner==2)
            return dp[t][m][c]=2;
            else if(winner!=1)
                flag=false;
            }
        }
        if(!flag)
            return dp[t][m][c]=0;
        else
            return dp[t][m][c]=1;
    }
    return dp[t][m][c];
  
}
int catMouseGame(vector<vector<int>>& graph) {
    int n=graph.size();
    memset(dp,-1,sizeof(dp));
    return util(0,1,2,graph,n);
}
};