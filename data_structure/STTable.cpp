/*
f(i,j)表示i ~ i+2^j-1区间最大值
    预处理
    f(i,j) = max( f(i,j-1),f(i+2^(j-1),j-1)
    查询l,r区间最值
    len = l-r+1;
    res = max( f(l,log(len)),f(r-log(len)+1,r))
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int a[10] = {10, 1, 2, 5, 2, 3, 4, 6, 7, 8};
    int f[10][5] = {0};
    int log[10] = {0};
    for (int i = 0; i <= n; i++) {
        f[i][0] = a[i];
    }
    log[1] = 0;
    log[2] = 1;
    for (int i = 3; i <= n; i++)
        log[i] = log[i / 2] + 1;
    for (int j = 1; j <= log[n]; j++) {
        for (int i = 0; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            // cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
        }
    }
    int l, r;
    while (cin >> l >> r) {
        int len = r - l + 1;
        int res = max(f[l][log[len]], f[r - (1 << log[len]) + 1][log[len]]);
        cout << res << endl;
    }
    return 0;
}
