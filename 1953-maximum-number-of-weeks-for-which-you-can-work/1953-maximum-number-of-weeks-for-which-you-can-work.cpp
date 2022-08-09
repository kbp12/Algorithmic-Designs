class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        long long ans = 0;
        sort(m.begin(),m.end());
        int n = m.size();
        for(int i=0;i<n;i++){
            ans+=m[i];
        }
        long long temp = ans-m[n-1];
        if(temp+1<m[n-1]){
            return temp+temp+1;
        }
        return ans;
    }
};