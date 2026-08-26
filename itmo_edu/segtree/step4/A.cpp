#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
	ll sum;

	Node(ll s){
		sum = s;
	}

	Node operator +(Node& o){
		return {sum + o.sum};
	}
};

class Stree{
private:
	int sz = 0;
	vector<Node> tree;

	int left(int x){
		return 2*x + 1;
	}

	int right(int x){
		return 2*x + 2;
	}

	void init(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		tree.assign(2 * sz, Node(0LL));
	}

	void build(vector<ll>& a , int x, int lx, int rx){
		if (rx - lx == 1){
			if(lx < (int) a.size()){
				tree[x] = Node((ll) a[lx]);
			}
			return;
		}
		int m = (lx + rx)/2;
		build(a, left(x), lx, m);
		build(a, right(x), m, rx);
		tree[x] = tree[left(x)] + tree[right(x)];
	}

	void set(int i, ll v, int x, int lx, int rx){
		if (rx - lx == 1){
			tree[x] = Node((ll) v);
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) set(i, v, left(x), lx, m);
		else set(i, v, right(x), m, rx);
		tree[x] = tree[left(x)] + tree[right(x)];
	}

	Node query(int l, int r, int x, int lx, int rx){
		if(rx <= l || lx >= r)
			return Node(0LL);

		if(lx >= l && rx <= r)
			return tree[x];

		int m = (lx + rx)/2;
		Node nl = query(l, r, left(x), lx, m);
		Node nr = query(l, r, right(x), m, rx);
		return nl + nr;
	}

public:
	Stree(int n){
		init(n);
	}

	void set(int i, ll v){
		set(i, v, 0, 0, sz);
	}

	void build(vector<ll>& a){
		build(a, 0, 0, sz);
	}

	ll query(int l, int r){
		return query(l, r, 0, 0, sz).sum;
	}

};

int n,m;


void slv(){
	vector<ll> a(n);
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	for(int i = 0 ; i < n ; i++){
		if(i % 2 == 1) a[i] = -a[i];
	}

	//for(int i = 0 ; i < n ; i++) cout<<a[i]<<" ";
	//cout<<"\n";

	Stree st(n);
	st.build(a);
	cin>>m;
	while(m--){
		int type; cin>>type;
		if(type == 0){
			int i; ll j; cin>>i>>j;
			i--;
			if(i % 2 == 1) j = -j;
			st.set(i,j);
			continue;
		}
		int l,r; cin>>l>>r;
		l--; r--;
		ll ans = st.query(l,r+1);
		if(l % 2 == 1) ans = -ans;
		cout<<ans<<"\n";
	}
}

int main(){
	while(cin >> n){
		slv();
	}
	return 0;
}

