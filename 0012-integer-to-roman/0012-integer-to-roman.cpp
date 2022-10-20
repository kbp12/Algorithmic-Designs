class Solution {
public:
    string intToRoman(int num) {
        vector<string>m = {"" , "M" , "MM" , "MMM"};
        vector<string>c = {"" , "C" , "CC" , "CCC" , "CD" , "D" , "DC" , "DCC" , "DCCC" , "CM"};
        vector<string>x = {"" , "X" , "XX" , "XXX" , "XL" , "L" , "LX" , "LXX" , "LXXX" , "XC"};
        vector<string>i = {"" , "I" , "II" , "III" , "IV" , "V" , "VI" , "VII" , "VIII" , "IX"};
        string ans = "";
        ans = m[num/1000]; num = num%1000;
        ans+=c[num/100]; num = num%100;
        ans+=x[num/10]; num = num%10;
        ans+=i[num];
        return ans;
    }
};