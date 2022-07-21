#include <bits/stdc++.h>
#define F first
#define S second
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
ll N = 1e6;
vi adj[N];
bool vis[N];
void DFS(ll s){
    if(vis[s])return;
    vis[s] = true;
    for(auto u:adj[s]){
        DFS(u);
    }
}
queue<ll>q;
ll dis[N];
void BFS(ll x){
    vis[x] = true;
    dis[x] = 0;
    q.push(x);
    while(!q.empty()){
        ll s = q.front();q.pop();
        for(auto u:adj[s]){
            if(vis[u])continue;
            vis[u] = true;
            dis[u] = dis[s]+1;
            q.push(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    return 0;
}