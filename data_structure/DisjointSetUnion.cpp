/*
并查集
路径压缩 
启发式合并（按秩合并）未实现
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10005;

int fa[MAXN];

// 初始化并查集
void init(int n) {
    for (int i = 0; i < n; i++)
        fa[i] = i;
    return;
}

// 查找所在集合
int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]); //路径压缩
    return fa[x];
}

// 合并
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    fa[x] = y;
    return;
}

// leetcode 547 Friend Circles
int findCircleNum(vector<vector<int>> &M) {
    int n = M.size();
    if (n <= 1)
        return n;
    init(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (M[i][j] == 1)
                merge(i, j);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (fa[i] == i) res++;
    }
    return res;
}

int main() {
    vector<vector<int>> M = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(M) << endl;
    return 0;
}
