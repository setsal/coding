/*
        Problem: 10038: Disk Tree
        subs: 230, ACs: 65, AcceptRate: 28.26, onsite: 32, access: 2591

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=10038&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

struct node {
    string str;
    map<string, int> next;
};

struct node nodes[1000000];
int trieSize;

void initTrie() {
    nodes[0].str = "";
    nodes[0].next.clear();
}

void insertTrie(vector<string> tmp) {
    int p = 0;
    for (int i = 0; i < tmp.size(); i++) {
        if (!nodes[p].next.count(tmp[i])) {
            nodes[trieSize].str = tmp[i];
            nodes[trieSize].next.clear();
            trieSize++;
            nodes[p].next[tmp[i]] = trieSize;
        }
        p = nodes[p].next[tmp[i]];
    }
    return;
}

int main() {
    int n;
    string s;

    while (cin >> n) {
        initTrie();
        trieSize = 1;

        for (int i = 0; i < n; i++) {
            cin >> s;

            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '\\') s[j] = ' ';
            }
            stringstream sin(s);
            string token;
            vector<string> tmp;
            while (sin >> token) {
                tmp.push_back(token);
            }
            insertTrie(tmp);
        }
    }
    return 0;
}