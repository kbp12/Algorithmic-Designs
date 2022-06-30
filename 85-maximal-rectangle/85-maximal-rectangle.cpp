class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int matrix[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                matrix[i][j] = mat[i][j]-'0';
            }
        }
        stack<int>st;
        int ans = 0;
        for(int i=0;i<rows;i++){
            if(i!=0){
                for(int j=0;j<cols;j++){
                    if(matrix[i][j]==1){
                        matrix[i][j]+=matrix[i-1][j];
                    }
                }
            }
            vector<int>left(cols,0), right(cols,0);
            for(int j=0;j<cols;j++){
                while(st.size() && matrix[i][st.top()]>=matrix[i][j]){
                    st.pop();
                }
                if(st.size()){
                    left[j] = st.top();
                }else{
                    left[j] = -1;
                }
                st.push(j);
            }
            while(st.size()){st.pop();}
            for(int j=cols-1;j>=0;j--){
                while(st.size() && matrix[i][st.top()]>=matrix[i][j]){
                    st.pop();
                }
                if(st.size()){
                    right[j] = st.top();
                }else{
                    right[j] = cols;
                }
                st.push(j);
            }
            while(st.size()){st.pop();}
            for(int j=0;j<cols;j++){
                ans = max(ans,(right[j]-left[j]-1)*matrix[i][j]);
                //cout<<ans<<" ";
            }
        }
        return ans;
    }
};