#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

void nimGame(){// removes the last stick wins the game
    int n;
    cin >> n;
    ll x = 0;
    for(int i = 0;i < n;i++){
        ll tmp;
        cin >> tmp;
        x ^= tmp;
    }
    if(x) cout << "first\n";
    else cout << "second\n";
}

void nimGame2(){// removes 1, 2, or 3 sticks
    int n;
    cin >> n;
    ll x = 0;
    for(int i = 0;i < n;i++){
        ll tmp;
        cin >> tmp;
        x ^= (tmp % 4);
    }
    if(x) cout << "first\n";
    else cout << "second\n";
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        nimGame2();
    }
    return 0;
}