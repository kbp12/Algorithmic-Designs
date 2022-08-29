class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>ans;
        set<pair<int,int>>s;
        for(auto queen:queens){
            s.insert({queen[0],queen[1]});
        }
        vector<pair<int,int>>dir = {{-1,0},{1,0},{0,1},{0,-1},{-1,-1}, {-1,1},{1,-1},{1,1}};
        for(int k=0;k<8;k++){
            int i = king[0], j = king[1];
            while(i>=0 and i<8 and j>=0 and j<8){
                if(s.find({i,j})!=s.end()){
                    ans.push_back({i,j});
                    break;
                }
                i+=dir[k].first;
                j+=dir[k].second;
            }
        }
        return ans;
    }
};