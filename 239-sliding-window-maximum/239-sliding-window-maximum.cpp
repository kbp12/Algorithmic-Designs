class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int  n = nums.size();
        int t = n-k+1;
        vector<int>ans(t,INT_MIN);
        deque<int>dq;
        for(int i=0;i<k;i++){
            if(dq.size()==0) dq.push_back(i);
            else{
                while(dq.size() && nums[dq.back()]<nums[i]) dq.pop_back();
                dq.push_back(i);
            }
        }
        ans[0] = nums[dq.front()];
        for(int i=k;i<n;i++){
            while(dq.size() && dq.front()<=(i-k)) dq.pop_front();
            while(dq.size() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            ans[i+1-k] = nums[dq.front()];
        }
        return ans;
    }
};