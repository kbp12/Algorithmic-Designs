class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<pair<int,int>>v(26,{-1,-1});
        for(int i=0;i<n;i++){
            int a = s[i]-'a';
            if(v[a].first==-1){
                v[a].first = v[a].second = i;
            }else{
                v[a].second = i;
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<26;i++){
            if(v[i].first==v[i].second and v[i].first!=-1){
                ans = min(ans,v[i].first);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};