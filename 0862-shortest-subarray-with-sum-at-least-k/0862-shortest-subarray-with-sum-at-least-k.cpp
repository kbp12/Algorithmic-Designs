class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        long long sum = 0;
        int ans = INT_MAX;
        for(int i=0; i<nums.size();i++){
            sum+= nums[i];
            if(sum >= k){
                ans = min(ans, i+1);
            }
            while( pq.size() && sum - pq.top().first >= k){
                pair<long long , int>p = pq.top(); pq.pop();
                ans = min(ans, i-p.second);
            }
            pq.push({sum, i});
        }
        return ans == INT_MAX?-1:ans;
    }
};