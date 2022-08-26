class Solution {
public:
    int minKnightMoves(int x, int y) {
        x+=300; y+=300;
        int moves = 0;
        queue<pair<int,int>>q;
        q.push({300,300});
        vector<vector<bool>>visit(601,vector<bool>(601,false));
        visit[300][300] = true;
        vector<int>xd = {1,2,2,1,-1,-2,-2,-1};
        vector<int>yd = {2,1,-1,-2,-2,-1,1,2};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front(); q.pop();
                int i = f.first; 
                int j = f.second;
                if(i==x and j==y) return moves;
                for(int k=0;k<8;k++){
                    int nx = i+xd[k];
                    int ny = j+yd[k];
                    if(nx>=0 and ny>=0 and nx<=600 and ny<=600 and visit[nx][ny]==false){
                        visit[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};