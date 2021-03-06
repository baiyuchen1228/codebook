#include <bits/stdc++.h>
#define F First
#define S Second
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

ll nxt() {
   ll x;
   cin >> x;
   return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n = nxt();
    ll m = nxt();
    vector<tuple<ll,ll,ll> > edges;
    for(int i = 0;i < m;i++){
        ll a = nxt();
        ll b = nxt();
        ll w = nxt();
        edges.push_back({a,b,w});
        }
    vi dis(n+1);
    for(int i = 1;i <= n;i++){
        dis[i] = 1e10;
    }
    dis[1] = 0;
    vi par(n+1);
    ll f;//log(nm);
    for(int i = 0;i <= n;i++){ // n-1
        f = -1;
        for(auto e:edges){
            ll a, b, w;
            tie(a,b,w) = e;
            if(dis[b] > dis[a]+w){
                dis[b] = dis[a]+w;
                par[b] = a;
                f = b;
            }
        }
    }
    if(f != -1){
        queue<ll> q;
        cout << "YES\n";
        for(int i = 0 ;i < n+1;i++)  f = par[f];
        vi cycle;
        for(ll v = f;;v = par[v]){
            cycle.push_back(v);
            if(v == f && cycle.size()>1){
                break;
            }
        }
        reverse(all(cycle));
        for(auto x:cycle){
            cout << x << ' ';
        }
    }
    else cout << "NO\n";

    return 0;
}