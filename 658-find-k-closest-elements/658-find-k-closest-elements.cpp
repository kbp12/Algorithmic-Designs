class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size()-1;
        while(r-l >=k){
            if(abs(x-arr[l]) <= abs(x-arr[r]))
                r--;
            else
                l++;
        }
        vector<int>ans;
        for(int i=l;i<=r;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};