class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>left(n), right(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(st.size() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.size()){
                left[i] = st.top();
            }else{
                left[i] = -1;
            }
            //cout<<left[i]<<" ";
            st.push(i);
        }
        //cout<<endl;
        while(st.size()){ st.pop(); }
        for(int i=n-1;i>=0;i--){
            while(st.size() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.size()){
                right[i] = st.top();
            }else{
                right[i] = n;
            }
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(left[i]<k && k<right[i]){
                ans = max(ans,nums[i]*(right[i]-left[i]-1));
            }
        }
        return ans;
    }
};