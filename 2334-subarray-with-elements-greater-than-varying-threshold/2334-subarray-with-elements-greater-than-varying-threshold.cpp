class Solution {
public:
    int validSubarraySize(vector<int>& nums, int th) {
        int n = nums.size();
        vector<int>left(n),right(n);
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
            st.push(i);
        }
        while(st.size()) st.pop();
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
        vector<int>siz(n);
        for(int i=0;i<n;i++){
            siz[i] = right[i]-left[i]-1;
            double d = th;
            d = th/siz[i];
            double temp = nums[i];
            if(temp>d) return siz[i];
            //cout<<siz[i]<<" ";
        }
        return -1;
    }
};