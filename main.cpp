#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    char c;
    int num;
    node(char ch,int x) : c(ch),num(x) {};
};

string reorganizeString(string s) {
    int len = s.size();
    vector<int> hash(26, 0);
    for (auto &c : s) {
        hash[c - 'a']++;
    }
    int most = *max_element(hash.begin(), hash.end());
    int legalMost = len % 2 == 0 ? len / 2 : len / 2 + 1;
    if (most > legalMost)
        return "";
    vector<node> str;
    for (int i = 0;i<26;i++) {
        if (hash[i]!=0) str.push_back(node((char)i+'a',hash[i]));
    }
    string res;
    char pre;
    while (res.size() < len) {
        int maxx = -1;
        int p = 0;
        for (int i = 0;i<str.size();i++) {
            if ((res.size() == 0 || str[i].c != pre) && str[i].num != 0 && maxx<str[i].num) {
                maxx = str[i].num;
                p = i;
            }
        }
        res += str[p].c;
        pre = str[p].c;
        str[p].num--;
    }
    return res;
}

int main() {
    string s ="vvvlo";
    while (cin>>s) {
        cout << reorganizeString(s) << endl;
    }
    return 0;
}