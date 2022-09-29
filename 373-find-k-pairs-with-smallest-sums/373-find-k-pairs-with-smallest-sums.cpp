class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        set<pair<int,int>>s;
        while(pq.size() and ans.size()<k){
            int sum = pq.top().first;
            auto [a,b] = pq.top().second; pq.pop();
            if(s.find({a,b})!=s.end()) continue;
            s.insert({a,b});
            ans.push_back({nums1[a],nums2[b]});
            if(a<n1-1 and b<n2-1) pq.push({nums1[a+1]+nums2[b+1],{a+1,b+1}});
            if(a<n1-1) pq.push({nums1[a+1]+nums2[b],{a+1,b}});
            if(b<n2-1) pq.push({nums1[a]+nums2[b+1],{a,b+1}});
        }
        return ans;
    }
};