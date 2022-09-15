class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        map<int,int>mpp;
        vector<int>ans;
        map<int,int>mp2;
        int z = 0;
        for(auto i:changed) {mp2[i]++; if(i==0) z++;}
        for(int i=0;i<changed.size();i++){
            if(mpp[changed[i]]>0){
                mpp[changed[i]]--;
            }else{
                if(mp2[2*changed[i]]>0){
                    mp2[2*changed[i]]--;
                }else{
                    return {};
                }
                mpp[2*changed[i]]++;
                ans.push_back(changed[i]);
            }
        }
        if(z%2) return {};
        return ans;
    }
};