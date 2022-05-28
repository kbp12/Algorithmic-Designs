class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int idx = 0, m = nums[0], n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>m){
                idx = i; m = nums[i];
            }
        }
        vector<int>ans(n);
        ans[idx] = -1;
        int i = 1;
        stack<int>st;
        st.push(idx);
        idx--;
        while(i<n){
            if(idx<0) idx = n-1;
            while(st.size() && nums[st.top()]<=nums[idx]){
                st.pop();
            }
            if(st.size()){
                ans[idx] = nums[st.top()];
            }else{
                ans[idx] = -1;
            }
            st.push(idx);
            i++;
            idx--;
        }
        return ans;
    }
};