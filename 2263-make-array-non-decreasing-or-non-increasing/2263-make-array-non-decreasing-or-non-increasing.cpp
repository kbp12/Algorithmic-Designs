class Solution {
public:
    int cost(vector<int>& nums, int d = 1) {
        int res = 0;
        priority_queue<int> pq;
        for (int i = d == 1 ? 0 : nums.size() - 1; i < nums.size() && i >= 0; i += d) {
            if (!pq.empty() && pq.top() > nums[i]) {
                res += pq.top() - nums[i]; pq.pop();
                pq.push(nums[i]);
            }
            pq.push(nums[i]);
        }
        return res;
    }
    int convertArray(vector<int>& nums) {
        return min(cost(nums), cost(nums, -1));
    }
};