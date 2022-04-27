class Solution {
public:
    int find_parent(vector<int>& v, int i) {
        if(v[i]==-1) return i;
        v[i] = find_parent(v,v[i]);
        return v[i];
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> v(n,-1);
        for (auto p : pairs) {
            int i = find_parent(v, p[0]), j = find_parent(v, p[1]);
            if (i != j) 
                v[j] = i;
        }
        
        vector<vector<int>> mpp(n);
        for (int i=0;i<n; ++i){
            int parent = find_parent(v,i);
            mpp[parent].push_back(i);
        }
        
        for (auto parents : mpp) {
            string temp = "";
            for (auto idx : parents) 
                temp += s[idx];
            sort(begin(temp), end(temp));
            
            for (int i=0; i<parents.size();i++) 
                s[parents[i]] = temp[i];
        }
        
        return s;
    }
};