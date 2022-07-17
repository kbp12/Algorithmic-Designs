class Solution {
public:
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        int n = nums.size(); 
        int m = q.size();
        vector<int>ans(m,0);
        
        for(int i=0;i<m;i++){  
            vector<pair<int , string >>vec(n);
            for(int j=0;j<n;j++){
                vec[j] = {j,nums[j]};
            }
            int firstt = q[i][0], secondd = q[i][1];
            
            for(int j=0;j<n;j++){
                int siz = vec[j].second.size(); 
                int idx = siz-secondd; 
                while(idx<siz-1 && vec[j].second[idx]=='0') idx++;
                    vec[j].second = vec[j].second.substr(idx);
            }
            sort(vec.begin(),vec.end(),
                [](pair<int,string>&p1, pair<int,string>&p2){
                        int siz1 = p1.second.size();
                        int siz2 = p2.second.size();
                        if(siz1!=siz2) return siz1<siz2;
                        if(p1.second!=p2.second) 
                            return p1.second<p2.second;
                        return p1.first<p2.first;
                });
            ans[i] = vec[firstt-1].first;
            vec.clear();
        }
        return ans;
    }
};