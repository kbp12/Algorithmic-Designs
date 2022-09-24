class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(), l =0;
        sort(position.begin(),position.end());
        int r = (position[n-1]-position[0])/(m-1);
        while(l<=r){
            int mid = l+(r-l)/2;
            int c=1;
            int prev = position[0];
            for(int i=1;i<n;i++){
                if(position[i]-prev>=mid){
                    prev = position[i];
                    c++;
                }
            }
            if(c>=m){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l-1;
    }
};