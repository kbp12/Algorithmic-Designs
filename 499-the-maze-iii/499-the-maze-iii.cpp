class Solution {
public:
    string ans = "";
    void dfs(int i,int j,int a,int b, vector<vector<int>>& maze, vector<vector<int>>& dist, int len,string &str){
        if(dist[i][j]<len) return;
        if(i==a and j==b and dist[i][j]==len){
            ans = min(ans,str);
            return;
        }
        dist[i][j] = len;
        if(i==a and j==b){
            ans = str;
            return;
        }  
        int l = j, r = j, u = i, d = i;
        while(l>0 and maze[i][l-1]!=1){
            l--; 
            if(l==b and i==a) 
                break;
        }
        if(l!=j){
            str+='l';
            dfs(i,l,a,b,maze,dist,len+abs(l-j),str);
            str.pop_back();
        }
        while(u>0 and maze[u-1][j]!=1){ 
            u--;
            if(u==a and j==b)
                break;
        }
        if(u!=i){
            str+='u';
            dfs(u,j,a,b,maze,dist,len+abs(i-u),str);
            str.pop_back();
        }
        while(r<maze[0].size()-1 and maze[i][r+1]!=1){ 
            r++;
            if(b==r and a==i){
                break;
            }
        }
        if(j!=r){
            str+='r';
            dfs(i,r,a,b,maze,dist,len+abs(j-r),str);
            str.pop_back();
        }
        while(d<maze.size()-1 and maze[d+1][j]!=1){ 
            d++;
            if(d==a and j==b)
                break;
        }
        if(d!=i){
            str+='d';
            dfs(d,j,a,b,maze,dist,len+abs(i-d),str);
            str.pop_back();
        }
        return;
    }
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        string str = "";
        dfs(ball[0],ball[1],hole[0],hole[1],maze,dist,0,str);
        return dist[hole[0]][hole[1]]==INT_MAX?"impossible":ans;
    }
};