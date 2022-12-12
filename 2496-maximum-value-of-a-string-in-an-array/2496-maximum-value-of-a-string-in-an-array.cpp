class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            bool dig = true;
            int val = 0;
            for(auto ch:strs[i]){
                if(ch>='0' and ch<='9'){
                    val = val*10 + (ch-'0');
                }else{
                    dig = false;
                    break;
                }
            }
            if(dig){
                ans = max(ans , val);
            }else{
                int l = strs[i].size();
                ans = max(ans , l);
            }
        }
        return ans;
    }
};