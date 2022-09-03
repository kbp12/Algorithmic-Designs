class Solution {
public:
    int xmin = INT_MAX, xmax = INT_MIN, ymin = INT_MAX, ymax = INT_MIN;
    vector<int>xd = {-1,1,0,0};
    vector<int>yd = {0,0,-1,1};
    void dfs(vector<vector<char>>& image, int x,int y){
        if(x<0 or y<0 or x>=image.size() or y>=image[0].size() or image[x][y]=='0') return;
        image[x][y] = '0';
        xmin = min(xmin,x); xmax = max(xmax,x);
        ymin = min(ymin,y); ymax = max(ymax,y);
        for(int k=0;k<4;k++){
            int i = x+xd[k], j = y+yd[k];
            dfs(image,i,j);
        }
        return;
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        dfs(image,x,y);
        return (xmax-xmin+1)*(ymax-ymin+1);
    }
};