class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int>umap;
        int ans = 0, mod = 1e9+7;
        for(auto d:deliciousness){
            for(int pow2=1;pow2<(1<<22);pow2*=2){
                ans = (ans + umap[pow2 - d])%mod;
            }
            umap[d]++;
        }
        return ans;
    }
};