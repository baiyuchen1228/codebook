#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
 
vector<ll> v1;
struct node{
    ll min,l,r;
    node *pl;
    node *pr;
};
void build(node* par,ll l,ll r){
    par->l = l;
    par->r = r;
    if(l == r){
        par->min = v1[l];
        return;
    }
    ll mid = (l+r)/2;
    build(par->pl = new node,l,mid);
    build(par->pr = new node,mid+1,r);
    par->min = min(par->pl->min,par->pr->min);
    return;
}
ll qry(node* par,ll l,ll r){
    if(l <= par->l && par->r <= r){
        return par->min; 
    }
    if(r < par->l || l > par->r){
        return __LONG_LONG_MAX__;
    }
    return min(qry(par->pl,l,r),qry(par->pr,l,r));
}
void prll(node* par){
    if(par->l == par->r){
        cout << par->l << ' ' << par->r << ' ' << par->min << '\n';
        return;
    }
    cout << par->l << ' ' << par->r << ' ' << par->min << '\n';
    prll(par->pl);
    prll(par->pr);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    for(ll i = 0;i < n;i++){
        ll tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    node *head;
    build(head = new node,0,n-1);
    for(ll i = 0;i < q;i++){
        ll l,r;
        cin >> l >> r;
        ll ans = qry(head,l-1,r-1);
        cout << ans << '\n';
    }
    //prll(head);
    return 0;
}