class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        for(auto a:nums) pq.push(a);
        long long res = 0;
        while(k--){
            res+=pq.top();
            long long temp = pq.top(); pq.pop();
            long long val = ceil(temp/ 3);
            if(temp%3) val++;
            pq.push(val);
        }
        return res;
    }
};