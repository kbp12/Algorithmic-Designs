class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        vector<int>left(n,0),right(n,0);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = 1+left[i-1];
            }
            if(ratings[n-1-i]>ratings[n-i]){
                right[n-1-i] = 1+right[n-i];
            }
        }
        for(int i=0;i<n;i++){
            ans += 1+max(left[i],right[i]);
        }
        return ans;
    }
};