/*
        Problem: 2009-24: Unique lines
        subs: 1107, ACs: 137, AcceptRate: 12.38, onsite: 40, access: 5557

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=2009-24&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

int x[10000];
int y[10000];

int pool_x[10000];
int pool_y[10000];

float gradient[10000];

int main() {
    int n;
    int node_num;
    int flag;
    float tmp_gradient, tmp2_gradient;
    int uniq_line_cnt;
    cin >> n;
    while (n--) {
        cin >> node_num;
        for (int i = 0; i < node_num; i++) {
            cin >> x[i] >> y[i];
        }

        uniq_line_cnt = 0;

        for (int i = 0; i < node_num - 1; i++) {      // last one bypass
            for (int j = i + 1; j < node_num; j++) {  // 算點的所有次數
                flag = 0;

                // get gradient
                if (x[j] == x[i]) {  // 兩點起始相同, 斜率給 max => 垂直線
                    tmp_gradient = float(INT_MAX);
                } else {
                    tmp_gradient = float(y[j] - y[i]) / float(x[j] - x[i]);
                }

                // check the same start point && gradient the same;
                // e.g. [(1, -1), (1, 1)] v.s. [(1, 0), (1, 1)]
                for (int k = 0; k < uniq_line_cnt; k++) {
                    if (pool_x[k] == x[j]) {
                        tmp2_gradient = float(INT_MAX);
                    } else {
                        tmp2_gradient =
                            float(pool_y[k] - y[j]) / float(pool_x[k] - x[j]);
                    }

                    if (tmp_gradient == tmp2_gradient &&
                        gradient[k] == tmp_gradient) {
                        flag = 1;
                        break;
                    }
                }

                if (!flag) {
                    pool_x[uniq_line_cnt] = x[j];
                    pool_y[uniq_line_cnt] = y[j];
                    gradient[uniq_line_cnt] = tmp_gradient;
                    uniq_line_cnt++;
                }
            }
        }
        cout << uniq_line_cnt << endl;
    }
    return 0;
}