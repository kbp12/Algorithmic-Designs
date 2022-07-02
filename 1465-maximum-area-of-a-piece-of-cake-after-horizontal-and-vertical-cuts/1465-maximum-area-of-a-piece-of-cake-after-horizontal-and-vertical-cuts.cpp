class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxh = horizontalCuts[0], maxw = verticalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++){
            maxh = max(maxh,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        maxh = max(maxh,h-horizontalCuts[horizontalCuts.size()-1]);
        for(int i=1;i<verticalCuts.size();i++){
            maxw = max(maxw,verticalCuts[i]-verticalCuts[i-1]);
        }
        maxw = max(maxw,w-verticalCuts[verticalCuts.size()-1]);
        long long a = maxh, b = maxw;
        int mod = 1e9+7;
        return (a*b)%mod;
    }
};