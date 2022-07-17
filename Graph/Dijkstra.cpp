#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

ll nxt() {
   ll x;
   cin >> x;
   return x;
}

int main(){// O(n+mlogm) no negative edge
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n = nxt();
    ll m = nxt();
    vector<vector<pi> > adj(n+1);
    for(int i = 0 ;i < m;i++){
        ll a = nxt();
        ll b = nxt();
        ll w = nxt();
        adj[a].pb({b,w});
        // adj[b].pb({a,w});
    }
    ll x = 1;
    ll dis[n+1];
    priority_queue<pi> pq;
    bool vis[n+1] = {0};
    for(int i = 1;i <= n;i++)dis[i] = 1e17;
    dis[x] = 0;
    pq.push({0,x});
    while(!pq.empty()){
        ll a = pq.top().second;pq.pop();
        if(vis[a])continue;
        vis[a] = true;
        for(auto u:adj[a]){
            ll b = u.first,w = u.second;
            if(dis[a] + w < dis[b]){
                dis[b] = dis[a]+w;
                pq.push({-dis[b],b});
            }
        }
    }
    for(int i = 1;i <= n;i++){
        cout << dis[i] << ' ';
    }
    cout << '\n';
    return 0;
}