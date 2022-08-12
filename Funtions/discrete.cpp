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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n]; // orginal number
	vector<int> v; // rank 
	for (int i=0; i<n; i++)  {
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin()); // if data repeat 
	for (int i=0; i<n; i++)  {
		a[i]=lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1; 
	}
	for (int i=0; i<n; i++)  {
		cout << a[i] << ' ';
	}
	cout << endl;
    return 0;
}