class Solution {
public:
    set<vector<int>>s;
    void solve(vector<int>& nums, int i, int n, vector<int>& v){
        if(i==n){
            if(v.size() > 1){
                s.insert(v);
            }
            return;
        }
        solve(nums,i+1,n,v);
        
        if(v.size()==0 or v.back() <= nums[i])
            v.push_back(nums[i]);
        else return;
        solve(nums,i+1,n,v);
        v.pop_back();
        return;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        solve(nums,0,n,v);
        return vector<vector<int>>(s.begin() , s.end());
    }
};