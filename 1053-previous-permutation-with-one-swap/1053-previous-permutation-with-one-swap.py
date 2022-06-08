class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        n = len(arr); pos = -1;
        for i in range(n-1):
            if(arr[i]>arr[i+1]):
                pos = i
        
        #if arr is sorted pos will remain as -1 so return the original array
        if(pos==-1):
            return arr
        
        pos_to_swap_with = pos+1;
        for j in range(pos+1,n,1):
            if(arr[j]<arr[pos] and arr[j]>arr[pos_to_swap_with]):
                pos_to_swap_with = j
        
        a = arr[pos]
        arr[pos] = arr[pos_to_swap_with]
        arr[pos_to_swap_with] = a
        
        return arr;