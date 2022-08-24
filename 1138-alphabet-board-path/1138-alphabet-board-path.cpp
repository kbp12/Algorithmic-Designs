class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans = "";
        int x1 = 0, y1 = 0;
        for (auto ch : target) {
            int x2 = (ch - 'a') % 5, y2 = (ch - 'a') / 5;
            //moving up
            ans += string(max(0,y1-y2),'U');
            //moving right
            ans += string(max(0,x2-x1),'R');
            //moving left
            ans += string(max(0,x1-x2),'L');
            //moving down
            ans += string(max(0,y2-y1),'D');
            //adding character
            ans += "!";
            x1 = x2;
            y1 = y2;
        }
        return ans;
    }
};