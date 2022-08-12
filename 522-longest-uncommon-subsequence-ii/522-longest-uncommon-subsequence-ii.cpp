class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        map<string,int>mpp;
        for(auto str:strs){
            mpp[str]++;
        }
        sort(strs.begin(),strs.end(),[](string & a, string &b){
            return a.size()>b.size();
        });
        for(int i=0;i<strs.size();i++){
            if(mpp[strs[i]]==1){
                bool found = false;
                int s1 = strs[i].size();
                for(int j=0;j<i;j++){
                    int s2 = strs[j].size();
                    int k=0, p = 0;
                    while(k<s1 and p<s2){
                        if(strs[i][k]==strs[j][p]){
                            k++; p++;
                        }else{
                            p++;
                        }
                    }
                    if(k==s1){
                        found = true;
                        break;
                    }
                }
                if(found==false) return strs[i].size();
            }
        }
        return -1;
    }
};