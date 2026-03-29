class Solution {
public:
    bool isValid(string s) {
        string stack = "";
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            if (c == '(' || c == '{' || c == '['){
                stack += c;
            }
            else{
                if (stack.empty()){
                    return false;
                }
                char top = stack[stack.size() - 1];
                if ((c == ')' && top == '(') || 
                    (c == ']' && top == '[') || 
                    (c == '}' && top == '{')){
                        stack.pop_back();
                    }
                    else{
                        return false;
                    }
            }
        }
        return stack.empty();
    }
};
