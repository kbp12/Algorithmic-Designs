class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int l=1,r = *max_element(quantities.begin(),quantities.end());
        while(l<r){
            int mid = l+(r-l)/2;
            int c = 0;
            for(int i=0;i<m;i++){
                c+=(quantities[i]/mid);
                if(quantities[i]%mid>0) c++;
            }
            if(c>n){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};