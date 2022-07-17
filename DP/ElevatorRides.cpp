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
int main(){// once two people
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n = nxt();
    ll x = nxt();
    vi v(n);
    for(auto &x :v)cin >> x;
    pair<ll, ll> p[1<<n];
    p[0] = {1, 0};
    for(int s = 1;s < (1 << n);s++){
        p[s] = {n+1, 0};
        for(int j = 0;j < n;j++){
            if(s & (1<<j)){
                pair<ll, ll> best = p[s ^ (1<<j)];
                if(best.S + v[j] <= x){
                    best.S += v[j];
                }
                else{
                    best.F++;
                    best.S = v[j];
                }
                p[s] = min(best,p[s]);
            }
        }
    }
    cout << p[(1 << n)-1].F << '\n';
}