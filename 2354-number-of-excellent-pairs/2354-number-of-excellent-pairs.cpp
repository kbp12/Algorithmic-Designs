class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<pair<int,int>>vec(33,{0,0});
        set<int>s;
        for(int i=0;i<nums.size();i++){
            int c = 0;
            int a = nums[i];
            if(s.find(a)!=s.end()) continue;
            s.insert(a);
            while(a){
                if(a&1) c++;
                a = a/2;
            }
            vec[c].second++;
        }
        long long res = 0;
        
        for(int i=0;i<33;i++){
            for(int j=0;j<33;j++){
                if(i+j>=k){
                    long long a = vec[i].second;
                    long long b = vec[j].second;
                    res+=a*b;
                }
            }
        }
        return res;
    }
};