class Solution {
public:
    int minimumRounds(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans=0;
        int n = a.size();
        int i=0;
        while(i<n){
            int c = 1;
            i++;
            while(i<n && a[i]==a[i-1]){
                i++;c++;
            }
            if(c<2) return -1;
            if(c%3 == 0) ans+= (c/3);
            else ans+= (c/3)+1;
        }
        return ans;
    }
};