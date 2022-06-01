class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int>l(n,0), r(n,0);
        int left = h[0], right = h[n-1];
        for(int i=1;i<n;i++){
            l[i] = left, r[n-1-i] = right;
            left = max(left,h[i]);
            right = max(right,h[n-1-i]);
        }
        int water = 0;
        for(int i=1;i<n-1;i++){
            water+= max(0,min(l[i],r[i])-h[i]);
        }
        return water;
    }
};