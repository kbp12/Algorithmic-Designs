class Solution {
public:
    vector<vector<int>>ans;
    
    void recur(vector<int>&arr,vector<int>&temp,int t,int i){
        if(i==arr.size()) return;
        if(t==0){
            ans.push_back(temp);
            return;
        }
        recur(arr,temp,t,i+1);
        if(t>=arr[i]){
            temp.push_back(arr[i]);
            recur(arr,temp,t-arr[i],i);
            temp.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        vector<int>temp;
        recur(arr,temp,t,0);
        return ans;
    }
};