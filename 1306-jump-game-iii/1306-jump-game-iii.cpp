class Solution {
public:
    bool canreach(vector<bool>& visited, int start, vector<int>& arr){
        if(start<0 || start>=arr.size() || visited[start])
            return false;
        visited[start]=true;
        if(arr[start]==0) return true;
        return canreach(visited,start-arr[start],arr) || canreach(visited,start+arr[start],arr);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>visited(n,false);
        return canreach(visited,start,arr);
    }
};