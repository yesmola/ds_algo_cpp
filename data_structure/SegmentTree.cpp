/*
线段树
a[1..n] original array
d[1..4n] segment tree
*/
#include <iostream>

using namespace std;

static const int MAXN = 10005;

struct STnode {
    int l;
    int r;
    int max;
    int sum;
    int lazy; // lazy propagation
};

int a[MAXN];
STnode d[4 * MAXN];

// 区间s t内建树
void build(int s, int t, int p) {
    d[p].l = s;
    d[p].r = t;
    if (s == t) {
        d[p].sum = a[s];
        d[p].max = a[s];
        return;
    }
    int mid = (s + t) / 2;
    build(s, mid, p * 2);
    build(mid + 1, t, p * 2 + 1);
    d[p].sum = d[p * 2].sum + d[p * 2 + 1].sum;
    d[p].max = max(d[p * 2].max, d[p * 2 + 1].max);
}

// 更新区间l,r 区间加上某个值c
void update(int l, int r, int c, int s, int t, int p) {
    if (l <= s && t <= r) {
        d[p].sum += (t - s + 1) * c;
        d[p].max += c;
        d[p].lazy += c;
        return;
    }
    int mid = (s + t) / 2;
    if (d[p].lazy != 0 && s != t) {
        d[p * 2].sum += d[p].lazy * (mid - s + 1);
        d[p * 2].max += d[p].lazy;
        d[p * 2].lazy += d[p].lazy;
        d[p * 2 + 1].sum += d[p].lazy * (t - mid);
        d[p * 2 + 1].max += d[p].lazy;
        d[p * 2 + 1].lazy += d[p].lazy;
        d[p].lazy = 0;
    }
    if (l <= mid)
        update(l, r, c, s, mid, p * 2);
    if (r > mid)
        update(l, r, c, mid + 1, t, p * 2 + 1);
    d[p].sum = d[p * 2].sum + d[p * 2 + 1].sum;
    d[p].max = max(d[p * 2].max, d[p * 2 + 1].max);
}

// 区间求和
int getSum(int l,int r,int s,int t,int p) {
    if (l<=s && t<=r) return d[p].sum;
    int mid = (s+t)/2;
    if (d[p].lazy) {
        d[p * 2].sum += d[p].lazy * (mid - s + 1);
        d[p * 2].max += d[p].lazy;
        d[p * 2].lazy += d[p].lazy;
        d[p * 2 + 1].sum += d[p].lazy * (t - mid);
        d[p * 2 + 1].max += d[p].lazy;
        d[p * 2 + 1].lazy += d[p].lazy;
        d[p].lazy = 0;
    }
    int sum = 0;
    if (l<=mid) sum += getSum(l,r,s,mid,p*2);
    if (r > mid) sum += getSum(l,r,mid+1,t,p*2+1);
    return sum;
}

// 区间求极值
int getMax(int l,int r,int s,int t,int p) {
    if (l<=s && t<=r) return d[p].max;
    int mid = (s+t)/2;
    if (d[p].lazy) {
        d[p * 2].sum += d[p].lazy * (mid - s + 1);
        d[p * 2].max += d[p].lazy;
        d[p * 2].lazy += d[p].lazy;
        d[p * 2 + 1].sum += d[p].lazy * (t - mid);
        d[p * 2 + 1].max += d[p].lazy;
        d[p * 2 + 1].lazy += d[p].lazy;
        d[p].lazy = 0;
    }
    int maxx = INT_MIN;
    if (l<=mid) maxx = max(maxx,getMax(l,r,s,mid,p*2));
    if (r > mid) maxx = max(maxx,getMax(l,r,mid+1,t,p*2+1));
    return maxx;
}

int main() {
    int n = 5;
    for (int i = 1;i<=n;i++) cin>>a[i];
    build(1,n,1);
    update(2,3,10,1,n,1);
    cout<<"getSum: "<<getSum(3,4,1,n,1)<<endl;
    cout<<"getMax: "<<getMax(3,4,1,n,1)<<endl;
    return 0;
}