/*
        Problem: 2008-37: Prefix expression evaluation
        subs: 1058, ACs: 216, AcceptRate: 20.42, onsite: 39, access: 5018

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=2008-37&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

bool flag;
stack<int> myStack;

bool check_legal(string op) {
    // validate
    if (myStack.size() == 0) return false;
    int num1 = myStack.top();
    myStack.pop();
    if (myStack.size() == 0) return false;
    int num2 = myStack.top();
    myStack.pop();

    int res = 0;
    if (op == "+")
        res = num1 + num2;
    else if (op == "-")
        res = num1 - num2;
    else if (op == "*")
        res = num1 * num2;
    else if (op == "/")
        res = num1 / num2;
    else if (op == "%")
        res = num1 % num2;
    myStack.push(res);
    return true;
}

int main() {
    string s, token;
    while (getline(cin, s) && s != ".") {
        stringstream sin(s);
        vector<string> dict;
        myStack = stack<int>();
        flag = false;

        while (sin >> token) {
            dict.push_back(token);
        }

        for (int i = dict.size() - 1; i >= 0; i--) {
            if (dict[i] == "+" || dict[i] == "-" || dict[i] == "*" ||
                dict[i] == "/" || dict[i] == "%") {
                if (!check_legal(dict[i])) {
                    cout << "illegal" << endl;
                    flag = 1;
                    break;
                }
            } else {
                // int value = stoi(dict[i]);
                int value = atoi(dict[i].c_str());
                myStack.push(value);
            }
        }
        if (!flag) {
            cout << myStack.top() << endl;
        }
    }

    return 0;
}