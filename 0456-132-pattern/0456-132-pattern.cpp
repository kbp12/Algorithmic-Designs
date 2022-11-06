class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n);
        v[0] = INT_MAX;
        int mini = nums[0];
        for(int i=1;i<n;i++){
            v[i] = mini;
            mini = min(mini , nums[i]);
        }
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size() and st.top()<=nums[i]){
                if(nums[i] != st.top() and st.top()>v[i]) return true;
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};