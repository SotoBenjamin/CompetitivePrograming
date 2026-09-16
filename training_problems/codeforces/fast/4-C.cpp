#include <bits/stdc++.h>
using namespace  std;
template <typename Key, typename Value, typename Hasher = std::hash<Key>>
class HashTable {
	struct Node {
			Key key;
			Value value;
			Node* next;
			Node(const Key& _key, const Value& _value, Node* _next = nullptr)
			: key(_key) , value(_value) , next(_next){}

	};

	Node* push_front(Node* head, const Key& k, const Value& v){
		Node* new_node = new Node(k,v);
		new_node->next = head;
		return new_node;
	}

	int n_keys = 0;
	int n_buckets = 0;
	std::vector<Node*> buckets; //buckets[i] = head of the linked list in slot i
	Hasher hasher;

	std::size_t index_of(const Key& k){
		return hasher(k) % n_buckets;
	}

	bool should_rehash(){
		return 4*(n_keys + 1) > 3 * n_buckets;
	}

	void rehash(){
		int new_n_buckets = n_buckets * 2;
		std::vector<Node*> new_buckets(new_n_buckets,nullptr);
		for(int i = 0 ; i < n_buckets ; i++){
			Node* cur = buckets[i];
			while(cur){
				Node* nxt = cur->next;

				std::size_t new_id = hasher(cur->key) % new_n_buckets;
				cur->next = new_buckets[new_id];
				new_buckets[new_id] = cur;

				cur = nxt;
			}
		}
		buckets = std::move(new_buckets);
		n_buckets = new_n_buckets;
	}

public:
	HashTable(int m = 8){
		n_buckets = m;
		buckets.assign(n_buckets,nullptr);
	}

	Value* find(const Key& k){
		std::size_t idx = index_of(k);
		Node* cur = buckets[idx];
		while(cur){
			if(cur->key == k){
				return &cur->value;
			}
			cur = cur->next;
		}
		return nullptr;
	}

	void insert(const Key& k, const Value& v){
		if(find(k) != nullptr) return;
		if(should_rehash()){
			rehash();
		}
		std::size_t idx = index_of(k);
		buckets[idx] = push_front(buckets[idx],k,v);
		n_keys++;
	}

	void erase(const Key& k){
		int idx = index_of(k);
		Node* cur = buckets[idx];
		if(!cur) return;
		if(cur->key == k){
			buckets[idx] = cur->next;
			delete cur;
			n_keys--;
			return;
		}
		Node* prev = cur;
		cur = cur->next;
		while(cur){
			if(cur->key == k){
				prev->next = cur->next;
				delete cur;
				n_keys--;
				return;
			}
			prev = cur;
			cur = cur->next;
		}
	}


	~HashTable() {
		for (int i = 0; i < n_buckets; i++) {
			Node* cur = buckets[i];
			while (cur) {
				Node* nxt = cur->next;
				delete cur;
				cur = nxt;
			}
		}
	}

	Value& operator[](const Key& k){
		std::size_t idx = index_of(k);
		Node* cur = buckets[idx];
		while(cur){
			if(cur->key == k){
				return cur->value;
			}
			cur = cur->next;
		}
		if(should_rehash()){
			rehash();
			idx = index_of(k);
		}
		buckets[idx] = push_front(buckets[idx],k,Value{});
		n_keys++;
		return buckets[idx]->value;
	}
};

int n;

string f(string& s, int x) {
	return s + to_string(x);
}

void slv() {
	HashTable<string,int> mp;
	for (int i = 0 ; i < n; i++) {
		string s; cin>>s;
		if (!mp.find(s)) {
			mp[s]++;
			cout<<"OK"<<"\n";
		}
		else {
			auto new_s = f(s,mp[s]);
			while (mp.find(new_s)) {
				mp[s]++;
				new_s = f(s,mp[s]);
			}
			mp[s]++;
			mp.insert(new_s,1);
			cout<<new_s<<"\n";
		}
	}
}


int main() {
	while (cin >>n ) {
		slv();
	}
    return 0;
}
