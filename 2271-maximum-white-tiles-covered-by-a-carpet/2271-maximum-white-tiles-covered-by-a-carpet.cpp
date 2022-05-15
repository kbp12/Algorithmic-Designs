class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int c) {
        int n = tiles.size();
        sort(tiles.begin(),tiles.end());
        int ans = 0;
        int count = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            while(j<n && tiles[i][0]+c>tiles[j][1]){
                count+= tiles[j][1]-tiles[j][0]+1;
                j++;
            }
            if(j!=n && tiles[i][0]+c>tiles[j][0]){
                ans = max(ans,count+tiles[i][0]+c-tiles[j][0]);
            }
            ans = max(ans,count);
            count-= tiles[i][1]-tiles[i][0]+1;
        }
        return ans;
    }
};