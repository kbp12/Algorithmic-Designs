class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        for(auto a:nums1) s1.insert(a);
        for(auto b:nums2){
            if(s1.find(b)!=s1.end()) return b;
        }
        return -1;
    }
};