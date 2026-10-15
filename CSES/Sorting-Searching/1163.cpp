#include<bits/stdc++.h>
#define ll long long
using namespace std;


int x;
int n;

struct cmp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
        int len1 = p1.second - p1.first;
        int len2 = p2.second - p2.first;
        if (len1  != len2) return len1 < len2;
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

pair<int,int> f(int x, set<int>& st) {
    auto it = st.lower_bound(x);
    int ri = *it;
    --it;
    int li = *it;
    st.insert(x);
    return {li,ri};
}


void slv() {
    set<int> st;
    st.insert(0);
    st.insert(x);
    multiset<pair<int,int> , cmp> ms;
    ms.insert({0,x});
    int a[n];
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    for (int i = 0 ; i <  n ; i++) {
        auto [li,ri] = f(a[i], st);
        //cout << li << " " << a[i] << " " << ri << '\n';
        ms.erase({li,ri});
        ms.insert({a[i],ri});
        ms.insert({li,a[i]});
        cout<<( ms.rbegin()->second - ms.rbegin()->first ) <<' ';
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (cin >> x >> n) {
        slv();
    }
}
