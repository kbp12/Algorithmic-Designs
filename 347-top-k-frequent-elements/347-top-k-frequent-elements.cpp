class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it:umap){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};