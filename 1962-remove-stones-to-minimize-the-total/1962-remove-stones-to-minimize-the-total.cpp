class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto pile:piles){
            pq.push(pile);
        }
        while(k--){
            int f = pq.top(); pq.pop();
            if(f==0){
                break;
            }
            if(f%2) pq.push(f/2+1);
            else pq.push(f/2);
        }
        int c = 0;
        while(pq.size()){
            c+=pq.top(); pq.pop();
        }
        return c;
    }
};