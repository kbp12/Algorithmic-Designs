class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end()); k--;
        while(k){pq.pop(); k--;}
        return pq.top();
    }
};