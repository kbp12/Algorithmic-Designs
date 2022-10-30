class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,pair<int,int>>umap;
        for(auto num:nums){
            if(umap.find(num%space) == umap.end()){
                umap[num%space] = {1 , num};
            }else{
                int c = umap[num%space].first;
                int mini = min(umap[num%space].second , num);
                umap[num%space] = {c+1 , mini};
            }
        }
        int ans = 0, max_c = 0;
        for(auto it:umap){
            if(it.second.first > max_c){
                ans = it.second.second;
                max_c = it.second.first;
            }else if(it.second.first == max_c){
                ans = min(ans , it.second.second);
            }
        }
        return ans;
    }
};