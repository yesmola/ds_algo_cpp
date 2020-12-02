/*
二叉堆实现最大堆
数组存放下标从1开始
*/
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 10005;

int h[MAXN];
int n;

// 堆的向上调整 参数为数组下标
void up(int i) {
    while (i > 1 && h[i] >= h[i / 2]) {
        swap(h[i], h[i / 2]);
        i /= 2;
    }
}

// 堆的向下调整 参数为数组坐标
void down(int i) {
    while (i * 2 <= n) {
        int t = i * 2;
        if (t + 1 <= n && h[t] < h[t + 1])
            t++;
        if (h[t] <= h[i])
            break;
        swap(h[t], h[i]);
        i = t;
    }
}

// 建堆 建堆有两种 从根开始向上调整 O(n log n) 或者 从叶子开始向下调整 O(n)
void build() {
    for (int i = n >> 1; i >= 1; i--)
        down(i);
}

// 打印堆
void printHeap() {
    for (int i = 1; i <= n; i++)
        cout << h[i] << " ";
    cout << endl;
}

//仿函数比较函数
struct cmp{
    bool operator()(int a,int b){
        return a<b;
    }
};

int main() {
    n = 10;
    // begin at i = 1
    int seed = 2;
    srand(seed);
    for (int i = 1; i <= n; i++) {
        h[i] = rand() % 100;
    }
    priority_queue<int,vector<int>,cmp> q;
    for (int i = 1;i<=n;i++) q.push(h[i]);
    while (!q.empty()) {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;

    build();
    printHeap();
    //堆排序
    while (n) {
        swap(h[1],h[n]);
        n--;
        down(1);
    }
    n = 10;
    printHeap();
    return 0;
}
