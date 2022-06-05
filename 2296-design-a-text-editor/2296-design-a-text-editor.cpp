class TextEditor {
public:
    stack<char>left,right;
    TextEditor() {}
    
    void addText(string text) {
        for(auto c:text) left.push(c);
        return;
    }
    
    int deleteText(int k) {
        int ans = min(k,(int)left.size());
        k = ans;
        while(k){left.pop(); k--;}
        return ans;
    }
    
    string cursorLeft(int k) {
        int ans = min(k,(int)left.size());
        k = ans;
        while(k){right.push(left.top()); left.pop(); k--;}
        int a = min(10,(int)left.size());
        vector<char>v(a);
        for(int i=a;i>0;i--){
            v[i-1] = left.top(); left.pop(); 
        }
        string str = "";
        for(int i=0;i<a;i++){
            left.push(v[i]);
            str.push_back(v[i]);
        }
        return str;
    }
    
    string cursorRight(int k) {
        int ans = min(k,(int)right.size());
        k = ans;
        while(k){left.push(right.top()); right.pop(); k--;}
        int a = min(10,(int)left.size());
        vector<char>v(a);
        for(int i=a;i>0;i--){
            v[i-1] = left.top(); left.pop(); 
        }
        string str = "";
        for(int i=0;i<a;i++){
            left.push(v[i]);
            str.push_back(v[i]);
        }
        return str;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */