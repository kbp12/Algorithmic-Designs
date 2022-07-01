class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),
            [](vector<int>&box1,vector<int>&box2){
                return box1[1]>box2[1];
            });
        int c = 0;
        int ans = 0;
        for(int i=0;i<boxTypes.size();i++){
            vector<int>&box =  boxTypes[i];
            if(c+box[0]<=truckSize){
                c+=box[0];
                ans+= (box[0]*box[1]);
            }else{
                ans+= (truckSize-c)*box[1];
                break;
            }
        }
        return ans;
    }
};