class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>m;
        for(auto num:nums){
            m[num]++;
        }
        int ans = 0;
        for(auto a:m){
            int f = a.first;
            int s = a.second;
            if(k == (2*f)){
                ans+=(s/2);
                m[f]-=s;
            }else{
                if(m.find(k-f)!=m.end()){
                    int t =min(m[f],m[k-f]);
                    ans+=t;
                    m[f]-=t;
                    m[k-f]-=t;
                }
            }
        }
        return ans;
    }
};