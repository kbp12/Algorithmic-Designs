class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int>f(26,-1),ff(26,-1);
        int i =0;
        for(auto c:s){
            if(f[c-'a']==-1){
                f[c-'a'] = i;
            }else{
                ff[c-'a'] = i;
            }
            i++;
        }
        for(int i=0;i<26;i++){
            if(f[i]!=-1){
                int d = ff[i]-f[i]-1;
                if(distance[i]!=d) return false;
            }
        }
        return true;
    }
};