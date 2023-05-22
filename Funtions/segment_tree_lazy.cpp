#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

vector<ll> v1;
struct node {
    ll val = 0, l, r;
    ll lazy = 0; // lazy propagation value
    node *pl;
    node *pr;
};
void build(node *par, ll l, ll r) {
    par->l = l;
    par->r = r;
    par->lazy = 0; // initialize lazy propagation value
    if (l == r) {
        par->val = v1[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(par->pl = new node, l, mid);
    build(par->pr = new node, mid + 1, r);
    par->val = par->pl->val + par->pr->val;
    return;
}

void propagate(node *par) {
    if (par->lazy != 0) {
        par->val += par->lazy; // update the current node value
        if (par->l != par->r) {
            // propagate lazy value to children
            par->pl->lazy += par->lazy;
            par->pr->lazy += par->lazy;
        }
        par->lazy = 0; // reset lazy propagation value
    }
}

void update(node *par, ll l, ll r, ll val) {
    if (l <= par->l && par->r <= r) {
        par->lazy += val; // update lazy propagation value
        propagate(par); // propagate the update
        return;
    }
    if (r < par->l || l > par->r) {
        return;
    }
    update(par->pl, l, r, val);
    update(par->pr, l, r, val);
    par->val = par->pl->val + par->pr->val;
    return;
}

ll qry(node *par, ll l, ll r) {
    propagate(par);
    if (l <= par->l && par->r <= r) {
        return par->val;
    }
    if (r < par->l || l > par->r) {
        return 0;
    }
    return qry(par->pl, l, r) + qry(par->pr, l, r);
}

void prll(node *par) {
    propagate(par);
    if (par->l == par->r) {
        cout << par->l << ' ' << par->r << ' ' << par->val << '\n';
        return;
    }
    cout << par->l << ' ' << par->r << ' ' << par->val << '\n';
    prll(par->pl);
    prll(par->pr);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, t, q;
    cin >> n >> t >> q;
    for (ll i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    node *root;
    build(root = new node, 0, n - 1);
    for (ll i = 0; i < t; i++) {
        ll l, r;
        cin >> l >> r >> val;
        update(root, l, r, val);
    }
    for(ll i = 0;i < t;i++){
        ll l,r;
        cin >> l >> r;
        query(root,l,r);
    }
    prll(root);
    return 0;
}