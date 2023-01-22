class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& s, int k) {
        sort(s.begin() , s.end() , [k](vector<int>& a, vector<int>& b){
            return a[k]>=b[k];
        });
        return s;
    }
};