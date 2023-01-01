class Solution {
public:
    int countDigits(int num) {
        string str = to_string(num);
        int cnt = 0;
        for(auto ch:str){
            if(num%(ch-'0') == 0) cnt++;
        }
        return cnt;
    }
};