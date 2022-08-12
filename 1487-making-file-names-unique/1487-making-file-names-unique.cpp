class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int n = names.size();
        vector<string>ans(n);
        map<string,int>mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(names[i])==mpp.end()){
                ans[i] = names[i];
                mpp[names[i]] = 1;
            }else{
                int x = mpp[names[i]];
                string new_str = names[i]+"("+to_string(x)+")";
                while(mpp.find(new_str)!=mpp.end()){
                    x++;
                    new_str = names[i]+"("+to_string(x)+")";
                }
                mpp[names[i]]++;
                mpp[new_str]++;
                ans[i] = new_str;
            }
        }
        return ans;
    }
};