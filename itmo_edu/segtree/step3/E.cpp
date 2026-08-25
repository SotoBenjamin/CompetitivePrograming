#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<#x<<" = "<<x<<endl;

using namespace std;

class Stree{
private:
	int sz = 0;
	vector<ll> tree;

	int left(int x){
		return 2*x + 1;
	}

	int right(int x){
		return 2*x + 2;
	}

	void set(int i, ll v, int x, int lx, int rx){
		if(rx - lx == 1){
			tree[x] += v;
			return;
		}
		int m = (lx + rx)/2;
		if(i < m) set(i, v, left(x), lx, m);
		else set(i, v, right(x), m, rx);
		tree[x] = tree[left(x)] + tree[right(x)];
	}

	ll query(int l, int r, int x, int lx, int rx){
		if(l >= rx || r <= lx){
			return 0;
		}

		if(lx >= l && rx <= r){
			return tree[x];
		}

		int m = (lx + rx)/2;

		return query(l, r, left(x), lx, m) + query(l, r, right(x), m, rx);
	}

public:
	Stree(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		tree.assign(2*sz,0);
	}

	void set(int i,int v){
		set(i, v, 0, 0, sz);
	}

	ll query(int l, int r){
		return query(l, r, 0, 0, sz);
	}
};

int n,m;


void slv(){
	Stree st(n+1);
	while(m--){
		int type; cin>>type;
		if(type == 1){
			int l,r,v; cin>>l>>r>>v;
			st.set(l,v);
			st.set(r,-v);
			continue;
		}
		int i; cin>>i;
		cout<<st.query(0,i+1)<<"\n";
	}
}

signed main(){
	// 5 0 0 0 0 -5
	// 0 1 2 3 4 5
	while(cin >> n >> m) slv();
	return 0;
}
