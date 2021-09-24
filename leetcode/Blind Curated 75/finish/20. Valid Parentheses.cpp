class Solution {
public:
    bool isValid(string s) {
        
        int length = s.size();
        
        stack<int> myStack;
        
        for (int i = 0; i < length; i++) {
            
            if (s[i] == '(') {
                myStack.push(')');
            }
            else if (s[i] == '{') {
                myStack.push('}');
            }
            else if (s[i] == '[') {
                myStack.push(']');
            }
            else if (myStack.empty() || myStack.top() != s[i]) {
                return false;
            }
            else {
                myStack.pop();
            }
            
        }
        
        return myStack.empty();
    }
};