class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i =0, j = num.size()-1;
        while(i<=j){
                if((num[i]=='1' and num[j]=='1') or (num[i]=='0' and num[j]=='0')or(num[i]=='8' and num[j]=='8')or(num[i]=='6' and num[j]=='9')or(num[i]=='9' and num[j]=='6')){
                    i++; j--;
                }else{
                    return false;
                }
        }
        return true;
    }
};