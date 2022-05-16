class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool>ans(m);
        for(int i=0;i<m;i++){
            int s = l[i], e = r[i];
            if(s==e){
                ans[i] = false;
                continue;
            }
            vector<int>v;
            while(s<=e){v.push_back(nums[s]); s++;}
            sort(v.begin(),v.end());
            int d = v[1]-v[0];
            bool yes = true;
            for(int j=2;j<v.size();j++){
                int c = v[j]-v[j-1];
                if(c!=d){
                    yes = false;  break;
                }
            }
            ans[i] = yes;
        }
        return ans;
    }
};