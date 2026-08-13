#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 7
using namespace std;

int n,m;

void slv(){
    vector<int> a(n+1) , b(m+1);
    a[n] = INF , b[m] = INF;
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    for(int i = 0 ; i < m ; i++) cin>>b[i];
    vector<int> ans(m);
    int i = 0;
    for(int j = 0 ; j < m ; j++){
        while(i < n && a[i] < b[j]) i++;
        ans[j] = i;
    }
    for(int i = 0 ; i < m ; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main(){
    while(cin >> n >> m) slv();
    return 0;
}
