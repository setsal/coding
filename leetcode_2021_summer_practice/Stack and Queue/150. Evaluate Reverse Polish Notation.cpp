class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                int res;
                if (tokens[i] == "+") {
                    res = n2 + n1;
                }
                else if (tokens[i] == "-") {
                    res = n2 - n1;
                }
                else if (tokens[i] == "*") {
                    res = n2 * n1;
                }
                else if (tokens[i] == "/") {
                    res = n2 / n1;
                }
                st.push(res);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};