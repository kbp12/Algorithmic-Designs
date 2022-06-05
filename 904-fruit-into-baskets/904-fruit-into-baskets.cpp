class Solution {
public:
    int totalFruit(vector<int>& f) {
        int a=0 ,b=0 ,c_a=0, c_b=0;
        int ans = 0, len = 0;
        for(int i=0;i<f.size();i++){
            if(f[i] == b){
                len++;
                c_b++;
            }else if(f[i]==a){
                len++;
                a = b;
                c_a = c_b;
                b = f[i];
                c_b = 1;
            }else{
                len = c_b+1;
                a = b;
                c_a = c_b;
                c_b = 1;
                b = f[i];
            }
            ans = max(ans,len);
        }
        return ans;
    }
};