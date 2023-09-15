#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for(int i = j; i <= k; i++)
struct Treap {
    Treap *l, *r;
    int pri, subsize; char val; bool rev_valid;
    Treap(int _val){
        val = _val;
        pri = rand();
        l = r = nullptr;
        subsize = 1; rev_valid = 0;
    }
    void pull(){    // update subsize or other information
        subsize = 1;
        for(auto i: {l,r}){
            if(i) subsize += i->subsize;
        }
    }
};
int size(Treap *treap) {
    if (treap == NULL) return 0;
    return treap->subsize;
}
// lazy
void push(Treap *t){
    if(!t) return;
    if(t->rev_valid){
        swap(t->l, t->r);
        if(t->l) t->l->rev_valid ^= 1;
        if(t->r) t->r->rev_valid ^= 1;
    }
    t->rev_valid = false;
}
Treap *merge(Treap *a, Treap *b){
    if(!a || !b) return a ? a : b;
    // push(a); push(b);    // lazy
    if(a->pri > b->pri){
        a->r = merge(a->r, b);
        a->pull();
        return a;
    }
    else {
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }

}
pair<Treap*, Treap*> split(Treap *root, int k) {    // 找前k個
	if (root == nullptr) return {nullptr, nullptr};
    // push(root); // lazy
	if (size(root->l) < k) {
		auto [a, b] = split(root->r, k - size(root->l) - 1);
		root->r = a;
		root->pull();
		return {root, b};
	}
    else {
		auto [a, b] = split(root->l, k);
		root->l = b;
		root->pull();
		return {a, root};
	}
}
void Print(Treap *t){
    if(t){
        Print(t->l);
        cout << t->val;
        Print(t->r);
    }
}
void substring_rev(){
    int n, m; cin >> n >> m;
    Treap *root = nullptr;
    string str; cin >> str;
    for(auto c : str){
        root = merge(root, new Treap(c));
    }
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        auto [a, b] = split(root, x-1); // a: 1~x-1, b: x~n
        auto [c, d] = split(b, y-x+1);  // 用b分割
        // c->rev_valid ^= true;
        // push(c);
        b = merge(a, d);    // 注意順序
        root = merge(b, c);
    }
    Print(root);
}