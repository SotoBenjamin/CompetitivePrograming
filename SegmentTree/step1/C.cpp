#include <bits/stdc++.h>
#define INF 1e9 + 7
using namespace std;

struct Node{
	int mn;
	int cnt;
	
	Node(int _mn, int _cnt) : mn(_mn) , cnt(_cnt) {}
	
	Node operator +(Node& o){
		int mn_res , cnt_res;
		if(mn < o.mn){
			mn_res = mn;
			cnt_res = cnt;
		}
		else if(o.mn < mn){
			mn_res = o.mn;
			cnt_res = o.cnt;
		}
		else{
			mn_res = mn;
			cnt_res = cnt + o.cnt;
		}
		return {mn_res , cnt_res};
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
		tree.assign(2 * sz, Node(INF,0));
	}
	
	void build(vector<int>& a , int x, int lx, int rx){
		if (rx - lx == 1){
			if(lx < (int) a.size()){
				tree[x] = Node(a[lx],1);
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
			tree[x] = Node(v,1);
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) set(i, v, left(x), lx, m);
		else set(i, v, right(x), m, rx);
		tree[x] = tree[left(x)] + tree[right(x)];
	}
	
	Node query(int l, int r, int x, int lx, int rx){
		if(rx <= l || lx >= r) 
			return Node(INF,0);
		
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
	
	pair<int,int> query(int l, int r){
		auto p = query(l, r, 0, 0, sz);
		return {p.mn, p.cnt};
	}
	
};



int main(){
	int n,m; cin>>n>>m;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	Stree st(n);
	st.build(a);
	
	while(m--){
		int t; cin>>t;
		if(t == 1){
			int i,v; cin>>i>>v;
			st.set(i,v);
			continue;
		}
		int l,r; cin>>l>>r;
		auto p = st.query(l,r);
		cout<<p.first<<" "<<p.second<<"\n";
	}
	return 0;
}
