#include <bits/stdc++.h>
//https://codeforces.com/gym/103640/problem/F
using namespace std;

int n,m;

const int MAX = 5e5;

vector<int> adj[MAX];

void dfs(int u, vector<char>& c) {
    c[u] = 'B';
    for (auto& v : adj[u]) {
        if (c[v] == '#') dfs(v, c);
    }
}

void slv() {
    for (int i = 1 ; i <= m ; i++) {
        int u, v; cin >> u >> v;
        if (u == n || v == n) continue;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<char> c(n+1,'#');

    dfs(n-1,c);

    for (int i = 1 ; i <= n ; i++)
        if (c[i] == '#') c[i] = 'A';

    for (int i = 1 ; i <= n ; i++) cout << c[i];
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        slv();
        for (int i = 1 ; i <= n ; i++) adj[i].clear();
    }
    return 0;
}