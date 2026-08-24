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
    vector<int> ans(n + m);
    int i = 0 , j = 0;
    while(i < n || j < m){
        if(a[i] < b[j]){
            ans[i+j] = a[i];
            i++;
        }
        else{
            ans[i+j] = b[j];
            j++;
        }
    }
    for(int& x : ans) cout<<x<<" ";
    cout<<"\n";
}

int main(){
    while(cin >> n >> m) slv();
    return 0;
}
