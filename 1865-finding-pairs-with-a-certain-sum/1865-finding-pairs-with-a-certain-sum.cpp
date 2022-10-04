class FindSumPairs {
public:
    unordered_map<int,int>mpp;
    vector<int>v1,v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto num2:nums2){
            mpp[num2]++;
        }
        v1 = nums1;
        v2 = nums2;
        return;
    }
    
    void add(int index, int val) {
        int v = v2[index];
        mpp[v]--;
        v2[index]+= val;
        mpp[v2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i=0;i<v1.size();i++){
            int diff = tot-v1[i];
            ans+=mpp[diff];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */