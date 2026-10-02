#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using ll = long long;
//https://codeforces.com/contest/1883/problem/D
using namespace std;
int n;
int q;


void slv() {
    ordered_set<pair<int,int>> ls,rs;
    map<pair<int,int>,vector<int>> items;
    ll cnt = 0;
    int id = 0;
    while (q--) {
        char c; int l,r;
        cin>>c>>l>>r;
        ll s = (ll) ls.size() - ls.order_of_key({r,INT_MAX}) ;
        s += (ll) rs.order_of_key({l,INT_MIN});
        if (c == '+') {
            cnt += s;
            ls.insert({l,id});
            rs.insert({r,id});
            items[{l,r}].push_back(id);
            id++;
        }
        else {
            int p = items[{l,r}].back();
            items[{l,r}].pop_back();
            cnt -= s;
            ls.erase({l,p});
            rs.erase({r,p});
        }
        if (cnt > 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main() {
    int t = 1; //cin>>t;
    while(cin >> q) slv();
    return 0;
}