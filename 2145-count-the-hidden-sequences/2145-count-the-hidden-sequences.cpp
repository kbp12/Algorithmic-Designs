class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int n = diff.size();
        long long h =0,l=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum>h) h = sum;
            if(sum<l) l = sum;
        }
        l = lower-l;
        h = upper-h;
        if(h-l+1 <0)return 0;
        return h-l+1;
    }
};