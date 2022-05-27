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
            while(st2.size() && h[st2.top()]>=h[n-1-i]){
                st2.pop();
            }
            if(st2.size()){
                r[n-1-i] = st2.top();
            }else{
                r[n-1-i] = n;
            }
            st2.push(n-1-i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,h[i]*(r[i]-l[i]-1));
        }
        return ans;
    }
};