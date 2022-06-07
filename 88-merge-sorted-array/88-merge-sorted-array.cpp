class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums3(m);
        for(int i=0;i<m;i++){
            nums3[i] = nums1[i];
        }
        int i=0, j= 0;
        while(i<m || j<n){
            if(i<m && j<n){
                if(nums3[i]<=nums2[j]){
                    nums1[i+j] = nums3[i]; i++;
                }else{
                    nums1[i+j] = nums2[j]; j++;
                }
            }else if(i==m){
                nums1[i+j] = nums2[j]; j++;
            }else{
                nums1[i+j] = nums3[i]; i++;
            }
        }
        return ;
    }
};