class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        int count = 1;
        int x=points[0][0],y=points[0][1];
        int i=1;
        while(i<n){
            int tempx = points[i][0];
            int tempy = points[i][1];
            if(tempx<=y){
                x = max(x,points[i][0]);
                y = min(y,points[i][1]);
            }else{
                count++;
                x = tempx;
                y = tempy;
                
            }
            i++;
        }
        return count;
    }
};