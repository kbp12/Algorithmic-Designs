class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i!=0){
                for(int j=0;j<m;j++){
                    if(mat[i][j]) mat[i][j]+=mat[i-1][j];
                }
            }
            stack<int>st;
            vector<int>sum(m,0);
            for(int j=0;j<m;j++){
                while(st.size() && mat[i][st.top()]>=mat[i][j]){
                    st.pop();
                }
                if(st.size()){
                    sum[j] = sum[st.top()];
                    sum[j]+= mat[i][j]*(j-st.top());
                }else{
                    sum[j]+= mat[i][j]*(j+1);
                }
                st.push(j);
            }
            for(auto s:sum) ans+=s;
            //cout<<ans<<" ";
        }
        return ans;
    }
};