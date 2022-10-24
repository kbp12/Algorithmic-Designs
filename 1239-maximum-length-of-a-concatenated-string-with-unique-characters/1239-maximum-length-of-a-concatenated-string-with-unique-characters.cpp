class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0, count, n = arr.size();
        for(int mask = 1; mask<(1<<n);mask++){
            int c[26] = {0};
            count = 0;
            bool ok = true;
            for(int j=0;j<n;j++){
                if((mask>>j) & 1){
                    for(auto ch:arr[j]){
                        if(c[ch-'a']){
                            ok = false;
                            break;
                        }
                        c[ch-'a'] = 1;
                        count++;
                    }
                }
                if(!ok) break;
            }
            if(ok){
                ans = max(ans , count);
            }
        }
        return ans;
    }
};