class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>left(k+1,0),right(k+1,0); 
        for(int i=1;i<=k;i++){
            left[i] = left[i-1] + cardPoints[i-1];
            right[k-i] = right[k+1-i] + cardPoints[n-i];
        }
        int ans = 0;
        for(int i=0;i<=k;i++){
            ans = max(ans,left[i]+right[i]);
        }
        return ans;
    }
};