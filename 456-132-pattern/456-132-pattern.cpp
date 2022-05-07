class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), s3 = INT_MIN;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<s3) return true;
            while(st.size() && nums[i]>st.top()){
                s3 = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};