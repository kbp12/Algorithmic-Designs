class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int l = 0, r = n-1, t = 0, b = n-1;
        int k=1;
        while(l<=r && t<=b){
            for(int i=l;i<=r;i++){ ans[t][i] = k; k++; }
            t++;
            for(int i=t;i<=b;i++){ ans[i][r] = k; k++; }
            r--;
            if(t<=b){
                for(int i=r;i>=l;i--){ ans[b][i] = k; k++; }
                b--;}
            if(l<=r){
                for(int i=b;i>=t;i--){ ans[i][l] = k; k++; }
                l++;}
        }
        return ans;
    }
};