class Solution {
public:
    vector<int>seg;
    vector<int>arr;
    int n;
    int maxseg(int l,int r, int wl, int wr, int idx){
        if(wr<l or wl>r) return 0;
        if(wl<=l and r<=wr) return seg[idx];
        int m = l+(r-l)/2;
        return max(maxseg(l,m,wl,wr,2*idx+1),maxseg(m+1,r,wl,wr,2*idx+2));
    }
    
    void update(int l, int r, int idx, int arr_idx, int val){
        if(arr_idx<l or arr_idx>r) return;
        seg[idx]= max(seg[idx],val);
        if(l==r) return;
        int m = l+(r-l)/2;
        update(l,m,2*idx+1,arr_idx,val);
        update(m+1,r,2*idx+2,arr_idx,val);
        return;
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        n = 100001;
        arr.resize(n,0);
        seg.resize(4*n,0);
        int ans = 0;
        for(auto num:nums){
            int res = maxseg(1,100000,max(1,num-k),num-1,0)+1;
            ans = max(ans,res);
            arr[num] = res;
            update(1,100000,0,num,res);
        }
        return ans;
    }
};