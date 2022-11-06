class Solution {
public:
    long long totalCost(vector<int>& a, int k, int sz) {
        int n = a.size();
        multiset<int> pr,sf;
        
        if(2*sz >= n){
            long long ans = 0;
            vector<int> v = a;
            sort(v.begin(),v.end());
            for(int i=0;i<k;i++){
                
                ans += v[i];
            }
            return ans;
        }
        
        for(int i=0;i<sz;i++){
            
            pr.insert(a[i]);
        }
        for(int j=n-1;j>=(n-sz);j--){
            
            sf.insert(a[j]);
        }
        
        int i = sz-1;
        int j = n-sz;
        long long ans = 0;
        int cnt = 0;
        while(i<j and cnt<k){
            
            
            
            int lf = (*pr.begin());
            int rg = (*sf.begin());
            
            if(lf <= rg){
                ans += lf;
                pr.erase(pr.find(lf));
                i++;
                if(i<j) pr.insert(a[i]);
            }
            
            else{
                ans += rg;
                sf.erase(sf.find(rg));
                j--;
                if(j>i) sf.insert(a[j]);
            
            }
            
            cnt++;
            
        }
        int rem = k-cnt;
        
        vector<int> z;
        for(auto x:pr) z.push_back(x);
        for(auto x:sf) z.push_back(x);
        
        sort(z.begin(),z.end());

        for(int p=0;p<rem;p++){

            ans += z[p];
        }
        

        
        return ans;
          
    }
};