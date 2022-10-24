class Solution {
public:
    int ans;
    void solve(vector<string>& arr, vector<bool>& taken , int i){
        if(i == taken.size()){
            bool ok = true;
            int count = 0;
            int c[26] = {0};
            for(int j=0;j<arr.size();j++){
                if(taken[j]){
                    for(auto ch:arr[j]){
                        if(c[ch-'a']) return;
                        c[ch-'a'] = 1;
                        count++;
                    }
                }
            }
            ans = max(ans , count);
            return;
        }
        solve(arr , taken , i+1);
        taken[i] = true;
        solve(arr , taken , i+1);
        taken[i] = false;
        return;
    }
    
    int maxLength(vector<string>& arr) {
        this->ans = 0;
        int n = arr.size();
        vector<bool>taken(n,false);
        solve(arr , taken , 0);
        return ans;
    }
};