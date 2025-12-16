#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define dbg(x) cerr<<#x<<" = "<<x<<endl;

#define all(x) x.begin(),x.end()

const int MAXN = 2e5 + 5;

using namespace std;

vector<vector<ll>> grid;
int n,m;
string s;

ll row_sum(int row){
    ll ans = 0;
    for(int j = 0 ; j < m ; ++j) ans += grid[row][j];
    return ans;
}

ll col_sum(int col){
    ll ans = 0;
    for(int i = 0 ; i < n ; ++i) ans += grid[i][col];
    return ans;
}

void slv(){
    cin>>n>>m;
    cin>>s;
    grid.assign(n,vector<ll>(m));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j) cin>>grid[i][j];
    }
    pair<int,int> cur = {0,0};
    for(char& c : s){
        if(c == 'D') {
            grid[cur.first][cur.second] = -1*row_sum(cur.first);
            cur.first += 1;
        }
        else {
            grid[cur.first][cur.second] = -1*col_sum(cur.second);
            cur.second += 1;
        }
    }
    grid[cur.first][cur.second] = -1*row_sum(cur.first);
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j) cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
}

signed main(){
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	  int t = 1; cin>>t;
	  while(t--) slv(); 
	  return 0;
}
