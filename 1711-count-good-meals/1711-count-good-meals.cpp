class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int>pow2;
        pow2.push_back(1);
        int temp = 2;
        for(int i=1;i<=21;i++){
            pow2.push_back(temp);
            temp*=2;
        }
        int ans = 0, m = pow2.size(), mod = 1e9+7;;
        unordered_map<int,int>umap;
        for(int i=0;i<deliciousness.size();i++){
            for(int j=0;j<m;j++){
                ans=( ans + umap[pow2[j] - deliciousness[i]])%mod;
            }
            umap[deliciousness[i]]++;
        }
        return ans;
    }
};