/*
树状数组 用1..n存数据
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static const int MAXN = 100005;
int a[MAXN];
int c[MAXN];
int n;

// lowbit用来处理当前节点应当管理几个节点
int lowbit(int x) {
    return x & (-x);
}

void add(int x,int val) {
    while (x<=n) {
        c[x] += val;
        x += lowbit(x);
    }
}

int getSum(int i) {
    int s = 0;
    while (i>=1) {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}

//leetcode 315 计算右侧小于当前元素的个数
// input  [5 2 6 1]
// output [2 1 1 0]
int getPos(int targt,vector<int>& p) {
    int l = 0; 
    int r = n-1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (p[mid] >= targt) r = mid-1;
        else {
            l = mid+1;
        }
    }
    return l;
}

vector<int> countSmaller(vector<int>& nums) {
    vector<int> p = nums;
    n = nums.size();
    sort(p.begin(),p.end());
    vector<int> res(n,0);
    for (int i = n-1;i>=0;i--) {
        //找到nums[i]在p中的位置
        int pos = getPos(nums[i],p);
        add(pos+1,1);
        res[i] = getSum(pos);
    }
    return res;
}

int main() {
    vector<int> nums = {5,2,6,1};
    vector<int> res = countSmaller(nums);
    for (int i = 0;i<res.size();i++) {
        cout<<res[i]<<endl;
    }
}
