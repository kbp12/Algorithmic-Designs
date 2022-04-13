class Solution {
public:
    int distributeCandies(vector<int>& c) {
        set<int>s;
        for(auto i:c) s.insert(i);
        return min(c.size()/2,s.size());
    }
};