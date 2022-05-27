class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int>st1,st2;
        vector<int>l(n),r(n);
        for(int i=0;i<n;i++){
            while(st1.size() && h[st1.top()]>=h[i]){
                st1.pop();
            }
            if(st1.size()){
                l[i] = st1.top();
            }else{
                l[i] = -1;
            }
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(st2.size() && h[st2.top()]>=h[i]){
                st2.pop();
            }
            if(st2.size()){
                r[i] = st2.top();
            }else{
                r[i] = n;
            }
            st2.push(i);
            
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,h[i]*(r[i]-l[i]-1));
        }
        return ans;
    }
};