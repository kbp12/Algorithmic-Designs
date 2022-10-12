class Solution {
public:
    vector<int>bitree;
    int n;
    int sumbit(int i){
        i++;
        int sum = 0;
        for(;i>0;i-=(i & (-i))){
            sum+=bitree[i];
        }
        return sum;
    }
    
    void addbit(int i, int val){
        i++;
        for(;i<=n;i+=(i & (-i))){
            bitree[i]+=val;
        }
        return;
    }
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        bitree.resize(n+1,0);
        vector<int>idx2(n);
        for(int i=0;i<n;i++){
            idx2[nums2[i]] = i;
        }
        long long ans = 0;
        for(int i=0;i<n-1;i++){
            int mid = idx2[nums1[i]];
            int smaller = sumbit(mid);
            int bigger = (n-1) - mid - (i-smaller);
            ans+= (long long) smaller*bigger;
            addbit(mid,1);
        }
        return ans;
    }
};