class Solution {
public:
//The draw condition is not appropriate though we can make such a graph which can have endless cycles and 
// moves can be different though on those cycles 
//so the draw codition will expand with the number of test cases i personally feel that
   int dp[501][51][51];
	int util(int t,int m,int c,vector<vector<int>>&graph,int n){
    //base cases
    if(t==5*n) dp[t][m][c]=0;
    //case 2 if mouse ever reaches the 0 whatever the moves or whatever the cat's pos mouse will win
    if(m==0) return dp[t][m][c]=1;
    //case 3 if mouse is caught by cat than he cant win,cat will win
    if(m==c) return dp[t][m][c]=2;
    
    //if state is reapeated
    if(dp[t][m][c]!=-1)
        return dp[t][m][c];
    //The mouse take first step so he will always going to have turn when step will be even
    int turn=t%2;
    if(turn==0){
        //if its turn of mouse than he wants to win so he can only win if the cat will lose on 
        //one of the next move he is going to take
        //the flag tells us about the draw condition
        //if none of them can win it will be a draw
        bool flag=true;
        for(int i=0;i<graph[m].size();i++){
            int winner=util(t+1,graph[m][i],c,graph,n);
            if(winner==1)
                return dp[t][m][c]=1;
            //this is a tricky part i.e every player wants to play optimally 
            //so either they want a win or if not possible  a draw 
            else if(winner!=2)
                flag=false;
        }
        //if we are out of that means mouse cant win so he will look for a draw next
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
    //because c++ want a return 
    return dp[t][m][c];
  
}
int catMouseGame(vector<vector<int>>& graph) {
    int n=graph.size();
    memset(dp,-1,sizeof(dp));
    return util(0,1,2,graph,n);
}
};