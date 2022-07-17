#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define FOR(s,a,b) for (int s = a; s <= b; s++)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

ll nxt() {
    ll x;
    cin >> x;
    return x;
}

map<int, vi> mp;
ll n;
ll m;
ll M = 1e9+7;
void Generate(ll ind ,ll n, ll prev, ll next ) {
    if(ind == n){
        mp[next].push_back(prev);
        return;
    }
    if((prev & (1 << ind)) != 0){
        Generate(ind + 1, n, prev, next);
        return;
    }
    if(ind < n -1 && (prev & (1 << ind+1)) == 0)
        Generate(ind + 2, n, prev, next);
    next |= (1 << ind);
    Generate(ind + 1, n, prev, next);
}
ll solution(){
    ll limit = (1 << n);
    for(ll i = 0;i < limit;i++){
        Generate((ll)0, n, i, (ll)0);
    }
    vi preRow(limit);
    vi DP(limit);
    preRow[0] = 1;
    for(ll i = 0;i < m;i++){
        for(ll j = 0;j < limit;j++){
            for(auto x : mp[j])
                DP[j] = (DP[j] + preRow[x]) % M;
        }
        swap(preRow,DP);
        fill(all(DP),0);
    }
    return preRow[0] % M;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    n = nxt();
    m = nxt();
    cout << solution() << '\n';
}