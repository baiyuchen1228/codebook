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

int main(){//O(n^3)
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n = nxt();
    ll m = nxt();
    ll q = nxt();
    ll adj[n+1][n+1] = {0};
    ll dis[n+1][n+1];
    for(int i = 0;i < m;i++){
        ll a = nxt();
        ll b = nxt();
        ll w = nxt();
        if(adj[a][b])w = min(adj[a][b],w);
        adj[a][b] = w;
        adj[b][a] = w;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j)dis[i][j] = 0;
            else if(adj[i][j]) dis[i][j] = adj[i][j];
            else dis[i][j] = 1e17;
        } 
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dis[i][j] = min(dis[i][j],
                                dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i = 0;i < q;i++){
        ll a = nxt();
        ll b = nxt();
        if(dis[a][b]==1e17)cout << "-1\n";
        else cout <<dis[a][b] << '\n';
    }
    return 0;
}