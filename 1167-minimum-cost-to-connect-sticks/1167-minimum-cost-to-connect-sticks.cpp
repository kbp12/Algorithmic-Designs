class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto stick:sticks) pq.push(stick);
        int ans = 0;
        while(pq.size()>1){
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            ans+=first+second;
            pq.push(first+second);
        }
        return ans;
    }
};