class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int n = d.size();
        vector<int>ans;
        int c = 0;
        d[n-1]++;
        for(int i=n-1;i>=0;i--){
            int a = d[i]+c;
            if(a>9){
                c = a/10;
                a = a%10;
            }else{
                c = 0;
            }
            ans.push_back(a);
        }
        if(c){
            ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};