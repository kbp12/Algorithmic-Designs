class Solution {
public:
    long long maximumBeauty(vector<int>& g,long long flowers,int t,int f,int p) {
        int n = g.size();
        sort(g.begin(),g.end());
        int filled = 0,temp = n-1;
        while(temp>=0){
            if(g[temp]<t)break;
            filled++; temp--;
        }
        if(filled == n) return (long long)filled * (long long)f;
        
        //preprocessing
        int m = n-filled;
        vector<long long>left(m,0),right(m,0);
        left[0]=0;
        for(int i=1;i<m;i++){ 
            left[i] = left[i-1]+ (long long)(g[i]-g[i-1])*(long long)i;
        }
        right[m-1] = t-g[m-1];
        for(int i=m-2;i>=0;i--){
            right[i] = right[i+1]+ (long long)(t-g[i]);
        }
        
        //finding solution
        long long ans = 0;
        for(int i=0;i<=m;i++){
            long long flower = flowers, tmp=0;
            if(i!=0){
                flower -= right[m-i]; 
            }
            if(flower<0) break;
            if(i!=m){
                int idx = (upper_bound(left.begin(),left.end(),flower)-left.begin());
                if(idx>(m-i)) idx = m-i;
                tmp = g[idx-1];
                tmp += (flower-left[idx-1])/idx;
                tmp = min(tmp,(long long)t-1);
            }
            long long res = tmp*(long long)p + (long long)(filled+i)*(long long)f;
            ans = max(ans,res);
        }
        return ans;
    }
};