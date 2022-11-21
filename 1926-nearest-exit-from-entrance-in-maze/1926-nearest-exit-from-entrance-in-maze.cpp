class Solution {
public:
    bool exist(int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int ans = 0;
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        while(!q.empty()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                auto it = q.front(); q.pop();
                maze[it.first][it.second] = '+';
                if((it.first==0 || it.first==m-1 || it.second==0 || it.second==n-1) && ans!=0){
                    return ans;
                }
                if(exist(it.first-1,it.second,m,n) && maze[it.first-1][it.second]=='.'){
                    q.push({it.first-1,it.second});
                    maze[it.first-1][it.second] = '+';
                }
                if(exist(it.first+1,it.second,m,n) && maze[it.first+1][it.second]=='.'){
                    q.push({it.first+1,it.second});
                    maze[it.first+1][it.second] = '+';
                }
                if(exist(it.first,it.second-1,m,n) && maze[it.first][it.second-1]=='.'){
                    q.push({it.first,it.second-1});
                    maze[it.first][it.second-1] = '+';
                }
                if(exist(it.first,it.second+1,m,n) && maze[it.first][it.second+1]=='.'){
                    q.push({it.first,it.second+1});
                    maze[it.first][it.second+1] = '+';
                }
                
            }
            ans++;
        }
        return -1;
    }
};