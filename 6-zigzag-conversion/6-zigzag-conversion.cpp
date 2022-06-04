class Solution {
public:
    string convert(string s, int n) {
        int m = s.length();
        if(n==1) return s;
        vector<vector<char>>v(n);
        int k = 0,i=0;
        bool down = true;
        while(i<m){
            if(down){
                if(k!=n-1){
                    v[k].push_back(s[i]); k++;
                }else{
                    v[k].push_back(s[i]); k--; down = false;
                }
            }else{
                if(k!=0){
                    v[k].push_back(s[i]); k--;
                }else{
                    v[k].push_back(s[i]); k++; down = true;
                }
            }
            i++;
        }
        string ans = "";
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].size();j++)
                ans.push_back(v[i][j]);
        }
        return ans;
    }
};