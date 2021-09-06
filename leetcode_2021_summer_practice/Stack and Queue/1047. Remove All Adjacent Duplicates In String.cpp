class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (auto item : s) {
            if (st.empty() || item != st.top()) {
                st.push(item);
            }
            else {
                st.pop();
            }
        }
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};