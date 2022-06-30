class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>left(n,0), right(n,0);
        for(int i=0;i<n;i++){
            while(st.size() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()){
                left[i] = st.top();
            }else{
                left[i] = -1;
            }
            st.push(i);
        }
        while(st.size()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(st.size() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()){
                right[i] = st.top();
            }else{
                right[i] = n;
            }
            st.push(i);
        }
        while(st.size()){st.pop();}
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};