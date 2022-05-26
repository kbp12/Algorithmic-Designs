class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](vector<int>& a, vector<int>& b){
           return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]); 
        });
        int ans = 0;
        int val = p[p.size()-1][1];
        for(int i=p.size()-2;i>=0;i--){
            if(p[i][1]<val){
                ans++;
            }else if(p[i][1]>val)
                val = p[i][1];
        }
        return ans;
    }
};