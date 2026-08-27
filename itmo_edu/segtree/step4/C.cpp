#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
	ll inv;
	vector<ll> f;
	Node(){
		inv = 0;
		f.assign(41,0);
	}
	Node(ll v){
		inv = 0;
		f.assign(41,0);
		if(v != -1) f[v] = 1;
	}
	
	ll cross(vector<ll>& a, vector<ll>& b){
		vector<ll> p(41,0);
		for(int i = 1 ; i <= 40 ; i++) p[i] = p[i-1] + a[i];
		ll ans = 0;
		for(int i = 1 ; i <= 40 ; i++) ans += p[i-1] * b[i];
		return ans;
	}
	
	vector<ll> add(vector<ll>& a, vector<ll>& b){
		vector<ll> res(41,0);
		for(int i = 0 ; i <= 40 ; i++) res[i] = a[i] + b[i];
		return res;
	}
	
	Node operator +(Node& o){
		ll inv1 = inv;
		ll inv2 = o.inv;
		ll inv3 = cross(f,o.f);
		Node res;
		res.inv = inv1 + inv2 + inv3;
		res.f = add(f,o.f);
		return res;
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
		tree.assign(2 * sz, Node(-1));
	}
	
	void build(vector<int>& a , int x, int lx, int rx){
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
	
	void set(int i, int v, int x, int lx, int rx){
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
			return Node();
		
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
	
	void set(int i, int v){
		set(i, v, 0, 0, sz);
	}
	
	void build(vector<int>& a){
		build(a, 0, 0, sz);
	}
	
	ll query(int l, int r){
		return query(l, r, 0, 0, sz).inv;
	}
	
};

int main(){
	int n,q; cin>>n>>q;
	Stree st(n);
	
	for(int i = 0 ; i < n ; i++){
		int x; cin>>x;
		st.set(i,x);
	}
	
	
	while(q--){
		int type; cin>>type;
		if(type == 1){
			int l,r; cin>>l>>r;
			l--; r--;
			cout<<st.query(l,r+1)<<"\n";
			continue;
		}
		int l,v;
		cin>>l>>v;
		l--;
		st.set(l,v);
	}
	return 0;
}
