class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& q) {
        int m = q.size();
        unordered_map<int,int> x,y,add,diff;
        unordered_map<int,unordered_set<int>>l;
        for(int i=0;i<lamps.size();i++){
            int a = lamps[i][0],b = lamps[i][1];
            if(l[a].find(b)==l[a].end()){
                l[a].insert(b);
                x[a]++; 
                y[b]++; 
                add[a+b]++;
                diff[a-b]++;
            }
        }
        vector<int>ans;
        for(auto qs:q){
            int a = qs[0], b = qs[1];
            if(x[a] || y[b] || add[a+b] || diff[a-b]){
                ans.push_back(1);
                for(int i=a-1;i<=a+1;i++){
                    for(int j=b-1;j<=b+1;j++){
                        if(l[i].find(j)!=l[i].end()){
                            x[i]--;
                            y[j]--;
                            add[i+j]--;
                            diff[i-j]--;
                            l[i].erase(j);
                        }
                    }
                }
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};