class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<heights.size()-1;i++){
            if(heights[i+1]>heights[i]){
                if(ladders){
                    ladders--; pq.push(heights[i+1]-heights[i]);
                }else{
                    if(pq.size() && heights[i+1]-heights[i]>pq.top()){
                        if(bricks>=pq.top()){
                            bricks-=pq.top(); pq.pop(); pq.push(heights[i+1]-heights[i]);
                        }else{
                            bricks-= (heights[i+1]-heights[i]);
                            if(bricks<0) return i;
                        }
                    }else{
                        bricks-= (heights[i+1]-heights[i]);
                        if(bricks<0) return i;
                    }
                }
            }
        }
        return heights.size()-1;
    }
};